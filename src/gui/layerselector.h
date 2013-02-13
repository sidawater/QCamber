#ifndef LAYERSELECTOR_H
#define LAYERSELECTOR_H
#include "QLabel"

class LayerSelector : public QLabel
{
    Q_OBJECT
public:
    LayerSelector(const QString &text,QWidget *parent = 0);
    ~LayerSelector(){}
    void setStyle(QString style){BGstyle = style;}
signals:
    void clicked();
    void DoubleClicked();
public slots:
    void slotClicked();
protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseDoubleClickEvent(QMouseEvent *);
private:
    int isSelected;
    QString BGstyle;
};

#endif // LAYERSELECTOR_H
