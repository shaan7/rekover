#include "getgeolocationcommand.h"

GetGeolocationCommand::GetGeolocationCommand(QObject *parent) :
    AbstractCommand(parent)
{
}

void GetGeolocationCommand::processCommand(const QStringList &commandLine)
{
    emit outputReady(commandLine.join(" "));
}

QStringList GetGeolocationCommand::supportedCommands() const
{
    return QStringList() << "getgeolocation";
}
