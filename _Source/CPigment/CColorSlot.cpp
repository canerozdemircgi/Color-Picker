#include "CColorSlot.hpp"

#include "CWidget/CLabelMask.hpp"
#include "CWidget/CLabelTarget.hpp"

#include <QtCore/QCache>

using namespace Qt::Literals::StringLiterals;

const CColorSlot* CColorSlot::SELECTION;

namespace
{

const QString path(u":/Checker/Slot.svg"_s);

QCache<const QString, const QPixmap> CACHE_PIXMAP_CHECKER(4);
QCache<const QString, const QPixmap> CACHE_PIXMAP_TARGET(8);
QCache<const QString, const QPixmap> CACHE_PIXMAP_MASK(4);

}

CColorSlot::CColorSlot(QWidget* const parent, std::pair<const uint8_t, const uint8_t> xy) :
	CLabelSvg(parent, {{.path = path, .keepAspectRatio = false}, {.cachePixmap = &CACHE_PIXMAP_CHECKER}}),

	xy(xy),

	Color_Widget(new QWidget(this)),
	Target_Label(new CLabelTarget(this->Color_Widget, &CACHE_PIXMAP_TARGET)),
	Mask_Label(new CLabelMask(this, {.cachePixmap = &CACHE_PIXMAP_MASK}))
{
	this->setSizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
	this->setMinimumSize(30, 30);

	this->Color_Widget->setProperty("hasNoBackground", true);
	this->Color_Widget->setAutoFillBackground(true);
	this->Target_Label->setVisible(false);
}

void CColorSlot::setBackgroundColor(const QColor& color) const
{
	this->Color_Widget->setPalette(color);
}

void CColorSlot::select() const
{
	if (CColorSlot::SELECTION == this)
		return;

	if (CColorSlot::SELECTION)
		CColorSlot::SELECTION->setSelected(false);
	CColorSlot::SELECTION = this;
	this->setSelected(true);
}

void CColorSlot::setSelected(bool selected) const
{
	this->Target_Label->setVisible(selected);
	this->Mask_Label->setVisible(!selected);
}

void CColorSlot::mouseReleaseEvent(QMouseEvent* const event)
{
	this->select();

	CLabelSvg::mouseReleaseEvent(event);
}

void CColorSlot::resizeEvent(QResizeEvent* const event)
{
	this->Color_Widget->setFixedSize(this->size());
	this->Target_Label->setFixedSize(this->size());
	this->Mask_Label->setFixedSize(this->size());

	CLabelSvg::resizeEvent(event);
}