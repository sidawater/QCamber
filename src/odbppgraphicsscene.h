#ifndef __ODBPPGRAPHICSSCENE_H__
#define __ODBPPGRAPHICSSCENE_H__

#include <QGraphicsScene>
#include <QPointF>

#include "symbol.h"

class ODBPPGraphicsScene: public QGraphicsScene {
  Q_OBJECT

public:
  ODBPPGraphicsScene(QObject* parent = 0);
  void setAreaZoomEnabled(bool status);
  void setViewScaleFactor(qreal factor);
  void updateSelection(Symbol* symbol);

  bool highlight(void);
  void setHighlight(bool status);
  void clearHighlight(void);

signals:
  void mouseMove(QPointF);
  void featureSelected(Symbol*);
  void rectSelected(QRectF);

protected:
  virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
  virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
  virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
  virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);

private:
  QGraphicsRectItem* m_rubberBand;
  QPointF m_rubberPS;
  QPointF m_rubberPE;
  bool m_areaZoomEnabled;
  bool m_highlight;
  bool m_rubberBandActivated;
  qreal m_viewScaleFactor;
  qreal m_penWidth;
  QList<Symbol*> m_selectedSymbols;
};

#endif /* __ODBPPGRAPHICSSCENE_H__ */
