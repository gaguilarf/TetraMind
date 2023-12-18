#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QLCDNumber>
#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <algorithm>
#include <random>
#include <vector>
#include <string>

#include "square.h"
#include "tetromino.h"
#include "utils.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    vector<string> datos;
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /**
   * @brief keyPressEvent Key event handler that takes care of the user input
   * @param event
   */
    void keyPressEvent(QKeyEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event);
    void cargarPalabras(vector<string>& datos);
    void generarPalabra(vector<string>& datos);

    /**
   * @brief renderTetromino Render tetromino to the correct scene
   * @param tetro Tetromino to render
   * @param scene Scene where to render the tetromino
   * @param type Which type of scene it was
   */
    void renderTetromino(Tetromino *tetro, QGraphicsScene *scene,
                         SceneType type = DEFAULT);

    /**
   * @brief blocks getter for the blocks_
   * @return
   */
    vector<Block> blocks() const;

private slots:
    /**
   * @brief tick The game tick which is called on the every timer timeout
   */
    void tick();

    /**
   * @brief Button click handlers
   */
    void on_startButton_clicked();
    void on_stopButton_clicked();

    /**
   * @brief move Move the currently active tetromino to a spesified direction if
   * it exists
   * @param direction Direction to move the tetromino to
   */
    void move(const Directions &direction);

    /**
   * @brief rotate Rotate the currently atcive tetromino
   * @param direction Direction to rotate the tetromino to
   */
    void rotate(const int &direction);

signals:
    /**
   * @brief setScore Set score signal
   * @param score
   */
    void setScore(int score);

private:
    /**
   * @brief takeHold Switch the current tetromino and the one in hold
   */
    void takeHold();

    /**
   * @brief checkRows Check if there is rows that need removing
   */
    void checkRows();

    /**
   * @brief deleteRow Delete the row at the spesified Y coordinates
   * @param y The row to delete
   */
    void deleteRow(const int &y);

    /**
   * @brief fallDown Instantly move the tetromino as down as possible
   */
    void fallDown();

    /**
   * @brief gameOver Execute game over
   */
    void gameOver();

    Ui::MainWindow *ui;

    QGraphicsScene *scene_;
    QGraphicsScene *nextScene_;
    QGraphicsScene *holdScene_;
    QTimer timer;

    const int BORDER_DOWN = ROWS * BLOCK;
    const int BORDER_RIGHT = COLUMNS * BLOCK;
    const int SMALL_BORDER_RIGHT = 6 * BLOCK;
    const int SMALL_BORDER_DOWN = 4 * BLOCK;

    Tetromino *nextTetrominion_ = nullptr;
    Tetromino *tetrominion_ = nullptr;
    Tetromino *holdTetrominion_ = nullptr;

    int score_ = 0;
    int tetrisCount_ = 0;
    bool justReleased_ = false;

    vector<Block> blocks_;

    default_random_engine randomEng;
    uniform_int_distribution<int> distr;

};
#endif // MAINWINDOW_H
