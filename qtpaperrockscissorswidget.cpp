#include "qtpaperrockscissorswidget.h"

#include <QImage>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

#include "paperrockscissorssimulation.h"
#include "ui_qtpaperrockscissorswidget.h"

QtPaperRockScissorsWidget::QtPaperRockScissorsWidget(
  const int width,
  const int height,
  const Init initialization,
  const int rng_seed,
  QWidget *parent
)
  : QWidget(parent),
    ui(new Ui::QtPaperRockScissorsWidget),
    m_pixmap(width,height),
    m_simulation(width,height,initialization,rng_seed)
{
  ui->setupUi(this);
  OnTimer();
  //Start a timer
  {
    QTimer * const timer{new QTimer(this)};
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(OnTimer()));
    timer->setInterval(1);
    timer->start();
  }
}

QtPaperRockScissorsWidget::~QtPaperRockScissorsWidget()
{
  delete ui;
}

void QtPaperRockScissorsWidget::OnTimer()
{
  using CellType = ribi::PaperRockScissors;

  m_simulation.Next();

  const int height{m_pixmap.height()};
  const int width{m_pixmap.width()};
  QImage image(width,height,QImage::Format_RGB32);
  const auto& grid = m_simulation.GetGrid();
  for (int y=0; y!=height; ++y)
  {
    for (int x=0; x!=width; ++x)
    {
      const auto celltype = grid[y][x];
      auto color = qRgb(0,0,0);
      const int brightness{196};
      switch (celltype)
      {
        case CellType::paper: color = qRgb(0,0,brightness); break;
        //case CellType::paper: color = qRgb(255,255,255); break;
        case CellType::rock: color = qRgb(brightness,0,0); break;
        //case CellType::rock: color = qRgb(0,0,0); break;
        case CellType::scissors: color = qRgb(0,brightness,0); break;
        //case CellType::scissors: color = qRgb(128,128,128); break;
      }
      image.setPixel(x,y,color);
    }
  }
  m_pixmap = QPixmap::fromImage(image);
  update();
}

void QtPaperRockScissorsWidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.drawPixmap(
    this->rect(),
    m_pixmap
  );
}

void QtPaperRockScissorsWidget::SetAll(
  const int width,
  const int height,
  const Init initialization,
  const int rng_seed
)
{
  m_pixmap = QPixmap(width,height);
  m_simulation = ribi::prs::PaperRockScissorsSimulation(
    width,
    height,
    initialization,
    rng_seed
  );
  update();
}
