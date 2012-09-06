#include <QtCore/QCoreApplication>

#include "commandprocessor.h"
#include "getgeolocationcommand.h"
#include "textmessagecommandsource.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CommandProcessor proc;
    proc.addCommand(new GetGeolocationCommand(&proc));
    proc.connectToCommandSource(new TextMessageCommandSource(&proc));

    return a.exec();
}
