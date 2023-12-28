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

class QSoundEffect;
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

    void keyPressEvent(QKeyEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event);
    void cargarPalabras(vector<string>& datos);
    void generarPalabra(vector<string>& datos);
    void limpiarHoldScene();
    void renderTetromino(Tetromino *tetro, QGraphicsScene *scene,
                         SceneType type = DEFAULT);

    vector<Block> blocks() const;

private slots:
    void tick();
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void move(const Directions &direction);
    void rotate(const int &direction);

signals:
    void setScore(int score);

private:

    QSoundEffect* m_backgroundMusic;
    void checkRows();
    void deleteRow(const int &y);
    void fallDown();
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
