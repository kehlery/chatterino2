#ifndef NOTEBOOKPAGE_H
#define NOTEBOOKPAGE_H

#include "QWidget"
#include "QRect"
#include "QVector"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QDragEnterEvent"
#include "notebookpage.h"
#include "notebooktab.h"
#include "chatwidget.h"
#include "notebookpagedroppreview.h"

class NotebookPage : public QWidget
{
Q_OBJECT

public:
    NotebookPage(QWidget *parent, NotebookTab *tab);
    NotebookTab* tab;
    QVBoxLayout parentbox;
    QHBoxLayout hbox;

    std::pair<int, int> removeFromLayout(ChatWidget* widget);
    void addToLayout(ChatWidget* widget, std::pair<int, int> position);

    static bool isDraggingSplit;
    static ChatWidget* draggingSplit;
    static std::pair<int, int> dropPosition;

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

    void dragEnterEvent(QDragEnterEvent *event) Q_DECL_OVERRIDE;
    void dragMoveEvent(QDragMoveEvent *event) Q_DECL_OVERRIDE;
    void dragLeaveEvent(QDragLeaveEvent *event) Q_DECL_OVERRIDE;
    void dropEvent(QDropEvent *event) Q_DECL_OVERRIDE;

    struct DropRegion
    {
        QRect rect;
        std::pair<int, int> position;

        DropRegion(QRect rect, std::pair<int, int> position)
        {
            this->rect = rect;
            this->position = position;
        }
    };

    std::vector<DropRegion> dropRegions;

    NotebookPageDropPreview preview;

private:
    void setPreviewRect(QPoint mousePos);
};

#endif // NOTEBOOKPAGE_H
