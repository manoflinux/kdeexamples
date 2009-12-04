#include "PlasmaAnimationExample.h"

#include <QFontMetrics>
#include <QGraphicsLinearLayout>
#include <QGraphicsLayoutItem>
#include <QPainter>
#include <QPauseAnimation>
#include <QPushButton>
#include <QSizeF>

#include <plasma/svg.h>
#include <plasma/theme.h>
#include <plasma/widgets/pushbutton.h>

#include <plasma/animations/animationgroup.h>
#include <plasma/animations/animation.h>

using namespace Plasma;

Q_DECLARE_METATYPE(QGraphicsWidget*)
Q_DECLARE_METATYPE(QGraphicsLayoutItem*)

K_EXPORT_PLASMA_APPLET(plasma-applet-pltest, PlasmaAnimationExample)

PlasmaAnimationExample::PlasmaAnimationExample(QObject *parent, const QVariantList &args)
    : Plasma::Applet(parent, args)
{
    // set a default size
    resize(300, 400);
}

void PlasmaAnimationExample::init()
{
    QGraphicsLinearLayout *mLayout = new QGraphicsLinearLayout(this);
    QGraphicsWidget *frontWidget = new QGraphicsWidget(this);
    QGraphicsLinearLayout *frontLayout = new QGraphicsLinearLayout(Qt::Vertical, frontWidget);

    PushButton* button1 = new PushButton(frontWidget);
    button1->setText("Press me!");

    PushButton *button2 = new PushButton(frontWidget);
    button2->setText("Pulse Animation!");

    PushButton* button3 = new PushButton(frontWidget);
    button3->setText("Grow Animation!");

    PushButton *button4 = new PushButton(frontWidget);
    button4->setText("Back Widget!");

    frontLayout->addItem(button1);
    frontLayout->addItem(button2);
    frontLayout->addItem(button3);

    qRegisterMetaType<QGraphicsLayoutItem *>("QGraphicsLayoutItem *");

    Animation* rotStackedAnim =
        Plasma::Animator::create(Plasma::Animator::RotationStackedAnimation, this);
    rotStackedAnim->setWidgetToAnimate(frontWidget);
    QVariant var;
    var.setValue(static_cast<QGraphicsWidget*>(button4));
    rotStackedAnim->setProperty("backWidget", var);
    rotStackedAnim->setProperty("reference", Animation::Center);
    rotStackedAnim->setProperty("movementDirection", Plasma::MoveRight);
    QVariant varLayout = rotStackedAnim->property("layout");
    mLayout->addItem(varLayout.value<QGraphicsLayoutItem*>());

    //animation
    Animation *rotAnim =
      Plasma::Animator::create(Plasma::Animator::RotationAnimation, this);
    rotAnim->setProperty("axis", Qt::ZAxis);
    rotAnim->setProperty("reference", Animation::Center);
    rotAnim->setProperty("angle", 180);
    rotAnim->setWidgetToAnimate(button1);

    Animation *fadeAnim =
      Plasma::Animator::create(Plasma::Animator::FadeAnimation, this);
    fadeAnim->setProperty("startOpacity", 0.8);
    fadeAnim->setProperty("targetOpacity", 0.2);
    fadeAnim->setWidgetToAnimate(button1);

    Animation *pulseAnim =
      Plasma::Animator::create(Plasma::Animator::PulseAnimation, this);
    pulseAnim->setWidgetToAnimate(button2);

    Animation *growAnim =
      Plasma::Animator::create(Plasma::Animator::GrowAnimation, this);
    growAnim->setProperty("factor", 2.0);
    growAnim->setWidgetToAnimate(button3);

    Animation *slideAnim =
      Plasma::Animator::create(Plasma::Animator::SlideAnimation, this);
    slideAnim->setProperty("movementDirection", Plasma::MoveDown);
    slideAnim->setProperty("distance", 30);
    slideAnim->setWidgetToAnimate(button3);

    QAbstractAnimation *pauseAnim = new QPauseAnimation(this);
    pauseAnim->setProperty("duration", 700);

    //group 'em up!
    inner_g = new Plasma::AnimationGroup();
    inner_g->setParallel(true);
    inner_g->add(rotAnim);
    inner_g->add(pulseAnim);
    inner_g->add(growAnim);

    outer_g = new Plasma::AnimationGroup(this);
    outer_g->add(inner_g);
    //TODO: fix slide
    //outer_g->add(slideAnim);
    outer_g->add(fadeAnim);
    outer_g->add(pauseAnim);
    outer_g->add(rotStackedAnim);

    connect(button1, SIGNAL(clicked()), this, SLOT(startAll()));
    connect(button4, SIGNAL(clicked()), this, SLOT(revertDirection()));
}

void PlasmaAnimationExample::revertDirection()
{
    if (outer_g->direction() == QAbstractAnimation::Forward) {
        outer_g->setDirection(QAbstractAnimation::Backward);
    } else {
        outer_g->setDirection(QAbstractAnimation::Forward);
    }
    outer_g->start();
}

void PlasmaAnimationExample::startAll()
{
    outer_g->setDirection(QAbstractAnimation::Forward);
    outer_g->start();
}


#include "PlasmaAnimationExample.moc"
