#include "Vector2.h"

// ------- CONSTRUCTORS ------------
Vector2::Vector2() 
{
	Initialize(0, 0);
}

Vector2::Vector2(std::nullptr_t)
{
	Initialize(0, 0);
}

Vector2::Vector2(float _f)
{
	Initialize(_f, _f);
}

Vector2::Vector2(float _x, float _y)
{
	Initialize(_x, _y);
}

void Vector2::Initialize(float _x, float _y)
{
	x = _x;
	y = _y;
}

// ------ STATICS -------------
const Vector2 Vector2::IHAT = Vector2(1, 0);
const Vector2 Vector2::JHAT = Vector2(0, 1);
const Vector2 Vector2::ZERO = Vector2(0, 0);
const Vector2 Vector2::ONE = Vector2(1, 1);

float Vector2::Cross(Vector2& a, Vector2& b)
{
	return a.x * b.y - a.y * b.x;
}

float Vector2::Dot(Vector2& a, Vector2& b)
{
	return a.x * b.x + a.y * b.y;
}

float Vector2::Len(Vector2& v)
{
	return (float)sqrt((double)Vector2::Len2(v));
}

float Vector2::Len2(Vector2& v)
{
	return v.x * v.x + v.y * v.y;
}

Vector2 Vector2::Add(Vector2& a, Vector2& b)
{
	return Vector2(a.x + b.x, a.y + b.y);
}

Vector2 Vector2::Scale(Vector2& v, float scale)
{
	return Vector2(v.x * scale, v.y * scale);
}

float Vector2::DistBetween(float x1, float y1, float x2, float y2)
{
	return (float)sqrt(Dist2Between(x1, y1, x2, y2));
}

float Vector2::DistBetween(Vector2& v1, Vector2& v2)
{
	return DistBetween(v1.x, v1.y, v2.x, v2.y);
}

float Vector2::Dist2Between(float x1, float y1, float x2, float y2)
{
	const float xDiff = x1 - x2;
	const float yDiff = y1 - y2;
	return xDiff * xDiff + yDiff * yDiff;
}

float Vector2::Dist2Between(Vector2& v1, Vector2& v2)
{
	return Dist2Between(v1.x, v1.y, v2.x, v2.y);
}

/**
 * finds the intersection of the two line segments, if there is one
 * 
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 * @param x3
 * @param y3
 * @param x4
 * @param y4
 * @param status 1 -> parallel, 0 -> found intersection, -1 -> no intersection
 * @return Vector, represent the point of intersection, or null if there is no intersection
 */
Vector2 Vector2::DoLinesIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int* status)
{
	const float denom = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);
	if (denom == 0.0f)  // Lines are parallel.
		*status = 1;
		return nullptr;
	
	const float ua = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denom;
	const float ub = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom;
	if (ua >= 0.0f && ua <= 1.0f && ub >= 0.0f && ub <= 1.0f) {
		// Get the intersection point.
		*status = 0;
		return Vector2((x1 + ua * (x2 - x1)), (y1 + ua * (y2 - y1)));
	}
	*status = -1;
	return nullptr;
}

/**
 * finds the intersection of the two line segments, if there is one
 *
 * @param v1
 * @param v2
 * @param v3
 * @param v4
 * @param status 1 -> parallel, 0 -> found intersection, -1 -> no intersection
 * @return Vector, represent the point of intersection, or null if there is no intersection
 */
Vector2 Vector2::DoLinesIntersect(Vector2& v1, Vector2& v2, Vector2& v3, Vector2& v4, int* status)
{
	return DoLinesIntersect(v1.x, v1.y, v2.x, v2.y, v3.x, v3.y, v4.x, v4.y, status);
}

void Vector2::Constrain(Vector2* v, float xMin, float xMax, float yMin, float yMax)
{
	if (v->x < xMin) v->x = xMin;
	else if (v->x > xMax) v->x = xMax;
	if (v->y < yMin) v->y = yMin;
	else if (v->y > yMax) v->y = yMax;
}

// -------- INSTANCE METHODS -------------
Vector2 Vector2::Add(float _x, float _y)
{
	return Vector2(x + _x, y + _y);
}

Vector2 Vector2::Sub(float _x, float _y)
{
	return Vector2(x - _x, y - _y);
}

Vector2 Vector2::Mult(float _x, float _y)
{
	return Vector2(x * _x, y * _y);
}

Vector2 Vector2::Div(float _x, float _y)
{
	if (_x == 0 || _y == 0) return nullptr;

	return Vector2(x / _x, y / _y);
}

Vector2& Vector2::operator=(const Vector2& v)
{
	x = v.x;
	y = v.y;
	
	return *this;
}

Vector2 Vector2::operator+(const Vector2& v)
{
	return Add(v.x, v.y);
}

Vector2 Vector2::operator-(const Vector2& v)
{
	return Sub(v.x, v.y);
}

Vector2 Vector2::operator*(const Vector2& v)
{
	return Mult(v.x, v.y);
}

Vector2 Vector2::operator*(const float f)
{
	return Mult(f, f);
}

Vector2 Vector2::operator/(const Vector2& v)
{
	return Div(v.x, v.y);
}

Vector2 Vector2::operator/(const float f)
{
	return Div(f, f);
}

bool Vector2::operator==(const Vector2& v)
{
	return (x == v.x) && (y == v.y);
}

bool Vector2::operator!=(const Vector2& v)
{
	return !operator==(v);
}

Vector2& Vector2::operator-=(const Vector2& v)
{
	x -= v.x;
	y -= v.y;

	return *this;
}

Vector2& Vector2::operator+=(const Vector2& v)
{
	x += v.x;
	y += v.y;

	return *this;
}

Vector2& Vector2::operator*=(const Vector2& v)
{
	x *= v.x;
	y *= v.y;

	return *this;
}

Vector2& Vector2::operator*=(const float f)
{
	x *= f;
	y *= f;

	return *this;
}

Vector2& Vector2::operator/=(const Vector2& v)
{
	x /= v.x;
	y /= v.y;

	return *this;
}

float Vector2::Cross(float _x, float _y)
{
	return x * _y - y * _x;
}

float Vector2::Cross(const Vector2& v)
{
	return x * v.y - y * v.x;
}

float Vector2::Dot(float _x, float _y)
{
	return x * _x + y * _y;
}

float Vector2::Dot(const Vector2& v)
{
	return x * v.x + y * v.y;
}
float Vector2::Len()
{
	return (float)sqrt(Len2());
}

float Vector2::Len2()
{
	return x * x + y * y;
}

Vector2 Vector2::Resize(float len)
{
	const float curLen = Len();
	if (curLen == 0) return nullptr;

	const float sclFctr = len / curLen;
	return Vector2(x * sclFctr,  y * sclFctr);
}

Vector2 Vector2::Unitize()
{
	return Resize(1);
}

Vector2 Vector2::Limit(float minLen, float maxLen)
{
	const float curLen = Len();
	if (curLen == 0) return nullptr;
	if (curLen > maxLen) return Resize(maxLen);
	if (curLen < minLen) return Resize(minLen);

	return GetCopy();
}

Vector2 Vector2::LimitMax(float maxLen)
{
	const float curLen = Len();
	if (curLen == 0) return nullptr;
	if (curLen > maxLen) return Resize(maxLen);

	return GetCopy();
}

Vector2 Vector2::LimitMin(float minLen)
{
	const float curLen = Len();
	if (curLen == 0) return nullptr;
	if (curLen < minLen) return Resize(minLen);

	return GetCopy();
}

Vector2 Vector2::Rotate(float degrees)
{
	return RotateRad(degrees * 3.14159 / 180);
}

Vector2 Vector2::RotateRad(float radians)
{
	const float _cos = (float)cos(radians);
	const float _sin = (float)sin(radians);
	return Vector2(x * _cos - y * _sin, x * _sin + y * _cos);
}

Vector2 Vector2::Rotate90(bool clockwise)
{
	if (clockwise) return Vector2(y, -x);
	return Vector2(-y, x);
}

Vector2 Vector2::ProjOnto(Vector2& v)
{
	return Scale(v, Dot(v) / v.Dot(v));
}

// object stuff
Vector2 Vector2::GetCopy()
{
	return Vector2(x, y);
}

std::string Vector2::ToString()
{
	return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}

void Vector2::SetTo(const Vector2& v)
{
	Initialize(v.x, v.y);
}

void Vector2::SetTo(float _x, float _y)
{
	Initialize(_x, _y);
}