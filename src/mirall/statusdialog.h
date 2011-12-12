/*
 * Copyright (C) by Klaas Freitag <freitag@kde.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#ifndef STATUSDIALOG_H
#define STATUSDIALOG_H

#include <QDialog>
#include <QStyledItemDelegate>
#include <QStandardItemModel>
#include <QUrl>

#include "ui_statusdialog.h"
#include "application.h"

namespace Mirall {

class FolderViewDelegate : public QStyledItemDelegate
{
    public:
    FolderViewDelegate();
    virtual ~FolderViewDelegate();

    enum datarole { FolderNameRole   = Qt::UserRole + 100,
                    FolderPathRole   = Qt::UserRole + 101,
                    FolderIconRole   = Qt::UserRole + 102,
                    FolderRemotePath = Qt::UserRole + 103,
                    FolderStatus     = Qt::UserRole + 104,
                    FolderErrorMsg   = Qt::UserRole + 105,
                    FolderStatusIcon = Qt::UserRole + 106 };
    void paint( QPainter*, const QStyleOptionViewItem&, const QModelIndex& ) const;
    QSize sizeHint( const QStyleOptionViewItem&, const QModelIndex& ) const;
};

class StatusDialog : public QDialog, public Ui::statusDialog
{
    Q_OBJECT
public:
    explicit StatusDialog(QWidget *parent = 0);
    void setFolderList( Folder::Map );
    void setOCUrl( const QUrl& );

signals:
    void removeFolderAlias( const QString& );
    void fetchFolderAlias( const QString& );
    void pushFolderAlias( const QString& );

public slots:
    void slotRemoveFolder();
    void slotFetchFolder();
    void slotPushFolder();
    void slotFolderActivated( const QModelIndex& );
    void slotOpenOC();

private:
    QStandardItemModel *_model;
    QUrl _OCUrl;
};
};

#endif // STATUSDIALOG_H