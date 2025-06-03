#ifndef ORDEREDMULTIMAP_H
#define ORDEREDMULTIMAP_H

#include <QtCore/qmap.h>

template<typename Key, typename Value>
class OrderedMultiMap
{
public:
    void enqueue(const Key &key, const Value &value)
    {
        auto it = m_queue.insert(key, value);
        m_iterators.append(it);
    }

    Value dequeue()
    {
        if (m_iterators.isEmpty())
            return Value();

        auto it = m_iterators.takeFirst();
        Value value = it.value();
        m_queue.erase(it);
        return value;
    }

    QPair<Key, Value> dequeuePair()
    {
        if (m_iterators.isEmpty())
            return QPair<Key, Value>();

        auto it = m_iterators.takeFirst();
        QPair<Key, Value> pair(it.key(), it.value());
        m_queue.erase(it);
        return pair;
    }

    void remove(const Key &key)
    {
        // We delete iterators using a predicate
        m_iterators.removeIf([&](auto it) {
            if (it.key() == key) {
                // The key match, we erase in the map directly
                m_queue.erase(it);
                // return true so it also get deleted in the iterator list
                return true;
            } else {
                return false;
            }
        });
    }

    int size()
    {
        return m_iterators.size();
    }

private:
    QMultiMap<Key, Value> m_queue;
    QList<typename QMultiMap<Key, Value>::Iterator> m_iterators;
};

#endif // ORDEREDMULTIMAP_H
