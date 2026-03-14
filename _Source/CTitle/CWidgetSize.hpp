#pragma once

#include <QtWidgets/QWidget>

class CWidgetSize final : public QWidget
{
public:
	class Direction final
	{
	public:
		static const Direction BOTTOM_LEFT;
		static const Direction BOTTOM_RIGHT;

		const QString name;
		const Qt::Edges edges;
		const Qt::CursorShape cursor;

		void (* const move)(QWidget* const widget);

	// friend class CWidgetSize;
	// friend class CWidgetsSize;
	};
	explicit CWidgetSize(QWidget* const parent, const CWidgetSize::Direction& direction);

	void move();

private:
	const CWidgetSize::Direction& direction;

	void showEvent(QShowEvent* const event) override;

	bool active;
	void mouseMoveEvent(QMouseEvent* const event) override;
	void mouseReleaseEvent(QMouseEvent* const event) override;

// friend class CWidgetsSize;
};