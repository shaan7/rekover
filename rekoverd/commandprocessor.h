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

#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include <QtCore/QObject>
#include <QtCore/QHash>
#include <QtCore/QStringList>
#include <QtCore/QList>

#include "abstractcommand.h"
#include "abstractcommandsource.h"

class CommandProcessor : public QObject
{
    Q_OBJECT
public:
    explicit CommandProcessor(QObject *parent = 0);
    void connectToCommandSource(AbstractCommandSource *commandSource);
    void addCommand(AbstractCommand *command);
    
public slots:
    void processCommand(const QString &commandLine, const QString &incidentId);

private:
    QHash<QString, AbstractCommand*> m_commands;
    QList<AbstractCommandSource*> m_sources;
};

#endif // COMMANDPROCESSOR_H
