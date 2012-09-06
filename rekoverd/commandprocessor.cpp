#include "commandprocessor.h"

#include <QDebug>

CommandProcessor::CommandProcessor(QObject *parent) :
    QObject(parent)
{
}

void CommandProcessor::connectToCommandSource(AbstractCommandSource *commandSource)
{
    m_sources.append(commandSource);
    connect(commandSource, SIGNAL(newCommand(QString)), SLOT(processCommand(QString)));
}

void CommandProcessor::processCommand(const QString commandLine)
{
    QStringList commandList = commandLine.split(" ");
    if (m_commands.contains(commandList.at(0))) {
        AbstractCommand *command = m_commands.value(commandList.at(0));
        connect(command, SIGNAL(outputReady(QString)),
                qobject_cast<AbstractCommandSource*>(sender()), SLOT(sendResponse(QString)));
        command->processCommand(commandList);
    }
}

void CommandProcessor::addCommand(AbstractCommand *command)
{
    Q_FOREACH(const QString &commandString, command->supportedCommands()) {
        m_commands.insert(commandString, command);
    }
}
