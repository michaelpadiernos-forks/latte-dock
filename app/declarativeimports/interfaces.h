/*
 * Copyright 2020  Michail Vourlakos <mvourlakos@gmail.com>
 *
 * This file is part of Latte-Dock
 *
 * Latte-Dock is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * Latte-Dock is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef APPINTERFACES_H
#define APPINTERFACES_H

// Qt
#include <QObject>


// Plasma
#include <PlasmaQuick/AppletQuickItem>

namespace Latte{

class Interfaces: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject *plasmoidInterface READ plasmoidInterface WRITE setPlasmoidInterface NOTIFY interfacesChanged)

    Q_PROPERTY(QObject *globalShortcuts READ globalShortcuts NOTIFY interfacesChanged)
    Q_PROPERTY(QObject *layoutsManager READ layoutsManager NOTIFY interfacesChanged)
    Q_PROPERTY(QObject *themeExtended READ themeExtended NOTIFY interfacesChanged)
    Q_PROPERTY(QObject *universalSettings READ universalSettings NOTIFY interfacesChanged)
    Q_PROPERTY(QObject *view READ view NOTIFY interfacesChanged)

public:
    explicit Interfaces(QObject *parent = nullptr);

    QObject *globalShortcuts() const;

    QObject *layoutsManager() const;

    QObject *themeExtended() const;

    QObject *universalSettings() const;

    QObject *view() const;

    QObject *plasmoidInterface() const;
    void setPlasmoidInterface(QObject *interface);

signals:
    void interfacesChanged();

private:
    QObject *m_globalShortcuts{nullptr};
    QObject *m_layoutsManager{nullptr};
    QObject *m_themeExtended{nullptr};
    QObject *m_universalSettings{nullptr};
    QObject *m_view{nullptr};

    PlasmaQuick::AppletQuickItem *m_plasmoid{nullptr};
};

}

#endif
