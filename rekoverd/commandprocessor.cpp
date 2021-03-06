/***************************************************************************
 *   Rekover is a tool for your N9/N950 to track it if stolen              *
 *                                                                         *
 *   Copyright 2012 by Shantanu Tushar <shantanu@kde.org>                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#include "commandprocessor.h"

#include <QDebug>

CommandProcessor::CommandProcessor(QObject *parent) :
    QObject(parent)
{
}

void CommandProcessor::connectToCommandSource(AbstractCommandSource *commandSource)
{
    m_sources.append(commandSource);
    connect(commandSource, SIGNAL(newCommand(QString, QString)), SLOT(processCommand(QString, QString)));
}

void CommandProcessor::processCommand(const QString &commandLine, const QString &incidentId)
{
    QStringList commandList = commandLine.split(" ");
    if (m_commands.contains(commandList.at(0))) {
        AbstractCommand *command = m_commands.value(commandList.at(0));
        command->processCommand(commandList, qobject_cast<AbstractCommandSource*>(sender()), incidentId);
    }
}

void CommandProcessor::addCommand(AbstractCommand *command)
{
    Q_FOREACH(const QString &commandString, command->supportedCommands()) {
        m_commands.insert(commandString, command);
    }
}
