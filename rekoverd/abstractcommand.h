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

#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

#include <QtCore/QObject>
#include <QtCore/QStringList>

class AbstractCommandSource;

class AbstractCommand : public QObject
{
    Q_OBJECT
public:
    explicit AbstractCommand(QObject *parent = 0);
    virtual QStringList supportedCommands() const = 0;

public slots:
    void processCommand(const QStringList &commandLine, AbstractCommandSource *commandSource, const QString &incidentId);

protected:
    QString incidentId() const;

protected slots:
    void sendResponse(const QString &response);

private slots:
    virtual void processCommandImpl(const QStringList &commandLine) = 0;

private:
    QString m_incidentId;
    AbstractCommandSource *m_commandSource;
};

#endif // ABSTRACTCOMMAND_H
