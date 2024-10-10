// cardwidget.h
   #pragma once

   #include <QWidget>
   #include <QLabel>
   #include <QVBoxLayout>
   #include "card.hpp"

   class CardWidget : public QWidget {
       Q_OBJECT

   public:
       CardWidget(const Card &card, QWidget *parent = nullptr);

   signals:
       void clicked();

   protected:
       void mousePressEvent(QMouseEvent *event) override;

   private:
       QLabel *nameLabel;
       QLabel *effectLabel;
   };