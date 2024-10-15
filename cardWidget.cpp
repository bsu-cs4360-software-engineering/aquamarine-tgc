// cardwidget.cpp
   #include "cardwidget.h"
   #include <QMouseEvent>

   CardWidget::CardWidget(const Card &card, QWidget *parent)
       : QWidget(parent)
   {
       setFixedSize(100, 150);
       setStyleSheet("background-color: white; border: 1px solid black;");

       QVBoxLayout *layout = new QVBoxLayout(this);
       nameLabel = new QLabel(QString::fromStdString(card.name), this);
       effectLabel = new QLabel(QString::fromStdString(card.effect), this);

       layout->addWidget(nameLabel);
       layout->addWidget(effectLabel);
   }

   void CardWidget::mousePressEvent(QMouseEvent *event)
   {
       if (event->button() == Qt::LeftButton) {
           emit clicked();
       }
       QWidget::mousePressEvent(event);
   }
   