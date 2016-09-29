/* Copyright (C) 2016 Rainmeter Project Developers
 *
 * This Source Code Form is subject to the terms of the GNU General Public
 * License; either version 2 of the License, or (at your option) any later
 * version. If a copy of the GPL was not distributed with this file, You can
 * obtain one at <https://www.gnu.org/licenses/gpl-2.0.html>. */

#ifndef RM_GFX_SHAPE_H_
#define RM_GFX_SHAPE_H_

#include "Util/D2DUtil.h"
#include <d2d1_1.h>
#include <wrl/client.h>
#include <vector>
#include <gdiplus.h>

namespace Gfx {

class Canvas;

enum class ShapeType : BYTE
{
	None = 0,
	Rectangle = 100,
	RoundedRectangle,
};

class __declspec(novtable) Shape
{
public:
	Shape(ShapeType type);
	~Shape();

	ShapeType GetShapeType() { return m_ShapeType; }

	D2D1_MATRIX_3X2_F GetShapeMatrix();
	D2D1_RECT_F GetBounds();
	bool IsShapeDefined();
	bool ContainsPoint(int x, int y);

	void SetOffset(int x, int y) { m_Offset = D2D1::SizeF((FLOAT)x, (FLOAT)y); }
	void SetFillColor(Gdiplus::Color color) { m_FillColor = Util::ToColorF(color); }
	void SetStrokeColor(Gdiplus::Color color) { m_StrokeColor = Util::ToColorF(color); }
	void SetStrokeWidth(int strokeWidth) { m_StrokeWidth = (float)strokeWidth; }
	void SetRotation(float rotation) { m_Rotation = rotation; }

protected:
	Microsoft::WRL::ComPtr<ID2D1Geometry> m_Shape;

private:
	friend class Canvas;

	ShapeType m_ShapeType;

	// Modifiers
	D2D1_SIZE_F m_Offset;
	D2D1_COLOR_F m_FillColor;
	D2D1_COLOR_F m_StrokeColor;
	float m_StrokeWidth;
	float m_Rotation;
};

} // Gfx

#endif
