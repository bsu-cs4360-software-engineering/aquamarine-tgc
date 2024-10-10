// mainwindow.h
   #pragma once

   #include <QMainWindow>
   #include <QVBoxLayout>
   #include <QHBoxLayout>
   #include <QPushButton>
   #include <QLabel>
   #include "game.hpp"
   #include "cardwidget.h"

   class MainWindow : public QMainWindow {
       Q_OBJECT

   public:
       MainWindow(QWidget *parent = nullptr);

   private slots:
       void drawCard();
       void playCard();
       void endTurn();

   private:
       void updateUI();

       Game game;
       QWidget *centralWidget;
       QVBoxLayout *mainLayout;
       QHBoxLayout *handLayout;
       QHBoxLayout *fieldLayout;
       QPushButton *drawButton;
       QPushButton *endTurnButton;
       QLabel *deckSizeLabel;
       QLabel *turnLabel;
   };
