#include <QtCore/qcoreapplication.h>
#include <QtCore/qtextstream.h>
#include <QtCore/qelapsedtimer.h>

#include "orderedmultimap.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QTextStream out(stdout);
    out << "-> User scores <-" << Qt::endl;

    OrderedMultiMap<QString, double> scores;
    scores.enqueue("Benjamain", 8.2);
    scores.enqueue("John", 7.8);
    scores.enqueue("Jean", 7.5); // Jean entry
    scores.enqueue("Jean", 7.2); // Jean entry
    scores.enqueue("Jean", 4.5); // Jean entry
    scores.enqueue("Ferry", 5.5);
    scores.enqueue("Ferry", 6.8);
    scores.enqueue("Jules", 5.5);

    QElapsedTimer timer;
    timer.start();

    scores.remove("Jean");

    out << "*removed 'Jean' entries in " << timer.nsecsElapsed() << " ns" << Qt::endl;

    QPair<QString, double> record;
    while (scores.size() > 0) {
        record = scores.dequeuePair();
        out << record.first << ": " << record.second << Qt::endl;
    }

    return 0;
}
