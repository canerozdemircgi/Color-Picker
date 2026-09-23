#pragma once

#include <QtWidgets/QWidget>

class CWidgetSize final : public QWidget
{
public:
	class Direction final
	{
	public:
		static const Direction TOP;
		static const Direction BOTTOM;
		static const Direction LEFT;
		static const Direction RIGHT;
		static const Direction TOP_LEFT;
		static const Direction TOP_RIGHT;
		static const Direction BOTTOM_LEFT;
		static const Direction BOTTOM_RIGHT;

		const QString name;
		const Qt::Edges edges;
		const Qt::CursorShape cursor;

		void (* const move)(QWidget& widget) noexcept;

	// friend class CWidgetSize;
	// friend class CWidgetsSize;
	};
	explicit CWidgetSize(QWidget* const parent, const CWidgetSize::Direction& direction) noexcept;

	void move() noexcept;

private:
	const CWidgetSize::Direction& direction;

	void showEvent(QShowEvent* const event) noexcept override;

	bool active;
	void mouseMoveEvent(QMouseEvent* const event) noexcept override;
	void mouseReleaseEvent(QMouseEvent* const event) noexcept override;

// friend class CWidgetsSize;
};