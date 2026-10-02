#pragma once

#include <QtWidgets/QMenu>

class CMenu final : public QMenu
{
public:
	struct Parameters final
	{
		const int8_t offsetX = 0;
		const int8_t offsetY = 0;
	};
	explicit CMenu(QWidget* const parent, const CMenu::Parameters& parameters) noexcept;

	void toggle() noexcept;

private:
	const QPoint offset;
	void move() noexcept;

	void mouseReleaseEvent(QMouseEvent* const event) noexcept override;

	bool eventFilter(QObject* const object, QEvent* const event) noexcept override;
};