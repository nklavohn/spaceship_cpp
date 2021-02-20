#include "Vector4.h"
#include "Vector2.h"

// static methods
float Vector4::Dot(Vector4* a, Vector4* b)
{
	return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}

float Vector4::Len(Vector4* v)
{
	return (float)sqrt(Len(v));
}

float Vector4::Len2(Vector4* v)
{
	return v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w;
}

Vector4 Vector4::Add(Vector4* a, Vector4* b)
{
	return Vector4(a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w);
}

Vector4 Vector4::Scale(Vector4* v, float scale)
{
	return Vector4(v->x * scale, v->y * scale, v->z * scale, v->w * scale);
}

float Vector4::DistBetween(Vector4* v1, Vector4* v2)
{
	Vector4 diff = Vector4(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z, v1->w - v2->w);
	return Len(&diff);
}

float Vector4::Dist2Between(Vector4* v1, Vector4* v2)
{
	Vector4 diff = Vector4(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z, v1->w - v2->w);
	return Len2(&diff);
}

Vector2 Vector4::DoLinesIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int* status) {
	return Vector2::DoLinesIntersect(x1, y1, x2, y2, x3, y3, x4, y4, status);
}

/**
 * @param status 1 -> parallel, 0 -> found intersection, -1 -> no intersection
 * @return Vector, represent the point of intersection, or null if there is no intersection
 */
Vector2 Vector4::DoLinesIntersect(Vector4* l1, Vector4* l2, int* status) {
	return DoLinesIntersect(l1->x, l1->y, l1->z, l1->w, l2->x, l2->y, l2->z, l2->w, status);
}


void Vector4::Constrain(Vector4* v, float xMin, float xMax, float yMin, float yMax, float zMin, float zMax, float wMin, float wMax)
{
	if (v->x < xMin) v->x = xMin;
	else if (v->x > xMax) v->x = xMax;
	if (v->y < yMin) v->y = yMin;
	else if (v->y > yMax) v->y = yMax;
	if (v->z < zMin) v->z = zMin;
	else if (v->z > zMax) v->z = zMax;
	if (v->w < wMin) v->w = wMin;
	else if (v->w > wMax) v->w = wMax;
}

// constructors
Vector4::Vector4()
{
	Initialize(0, 0, 0, 0);
}

Vector4::Vector4(std::nullptr_t)
{
	Initialize(0, 0, 0, 0);
}

Vector4::Vector4(float f)
{
	Initialize(f, f, f, f);
}

Vector4::Vector4(Vector2 v1, Vector2 v2)
{
	Initialize(v1.x, v1.y, v2.x, v2.y);
}

Vector4::Vector4(float _x, float _y, float _z, float _w)
{
	Initialize(_x, _y, _z, _w);
}

void Vector4::Initialize(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

// static constants
const Vector4 Vector4::ZERO = Vector4(0, 0, 0, 0);
const Vector4 Vector4::ONE = Vector4(1, 1, 1, 1);

// arithmetic
Vector4 Vector4::Add(float _x, float _y, float _z, float _w)
{
	return Vector4(x + _x, y + _y, z + _z, w + _w);
}

Vector4 Vector4::Sub(float _x, float _y, float _z, float _w)
{
	return Vector4(x - _x, y - _y, z - _z, w - _w);
}

Vector4 Vector4::Mult(float _x, float _y, float _z, float _w)
{
	return Vector4(x * _x, y * _y, z * _z, w * _w);
}

Vector4 Vector4::Div(float _x, float _y, float _z, float _w)
{
	return Vector4(x / _x, y / _y, z / _z, w / _w);
}

Vector4& Vector4::operator=(const Vector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.z;

	return *this;
}

Vector4& Vector4::operator+=(const Vector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;

	return *this;
}

Vector4& Vector4::operator-=(const Vector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;

	return *this;
}

Vector4& Vector4::operator*=(const Vector4& v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	w *= v.w;

	return *this;
}

Vector4& Vector4::operator*=(const float f)
{
	x *= f;
	y *= f;
	z *= f;
	w *= f;

	return *this;
}

Vector4& Vector4::operator/=(const Vector4& v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	w /= v.w;

	return *this;
}

Vector4 Vector4::operator+(const Vector4& v)
{
	return Add(v.x, v.y, v.z, v.w);
}

Vector4 Vector4::operator-(const Vector4& v)
{
	return Sub(v.x, v.y, v.z, v.w);
}

Vector4 Vector4::operator*(const Vector4& v)
{
	return Mult(v.x, v.y, v.z, v.w);
}

Vector4 Vector4::operator*(const float f)
{
	return Mult(f, f, f, f);
}

Vector4 Vector4::operator/(const Vector4& v)
{
	return Div(v.x, v.y, v.z, v.w);
}

Vector4 Vector4::operator/(const float f)
{
	return Div(f, f, f, f);
}

bool Vector4::operator==(const Vector4& v)
{
	return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w);
}

bool Vector4::operator!=(const Vector4& v)
{
	return !operator==(v);
}

// vector algrebra
float Vector4::Dot(float _x, float _y, float _z, float _w)
{
	return x * _x + y * _y + z * _z + w * _w;
}

float Vector4::Dot(Vector4* v)
{
	return x * v->x + y * v->y + z * v->y + w * v->w;
}

float Vector4::Len()
{
	return (float)sqrt(Len2());
}

float Vector4::Len2()
{
	return x * x + y * y + z * z + w * w;
}

Vector4 Vector4::Resize(float len)
{
	const float curLen = Len();
	if (curLen == 0) return nullptr;

	const float sclFctr = len / curLen;
	return Vector4(x * sclFctr, y * sclFctr, z * sclFctr, w * sclFctr);
}

Vector4 Vector4::Unitize()
{
	return Resize(1);
}

Vector4 Vector4::Limit(float minLen, float maxLen)
{
	const float curLen = Len();
	if (curLen == 0) return nullptr;
	if (curLen > maxLen) return Resize(maxLen);
	if (curLen < minLen) return Resize(minLen);

	return GetCopy();
}

Vector4 Vector4::LimitMax(float maxLen)
{
	const float curLen = Len();
	if (curLen == 0) return nullptr;
	if (curLen > maxLen) return Resize(maxLen);

	return GetCopy();
}

Vector4 Vector4::LimitMin(float minLen)
{
	const float curLen = Len();
	if (curLen == 0) return nullptr;
	if (curLen < minLen) return Resize(minLen);

	return GetCopy();
}

Vector4 Vector4::ProjOnto(Vector4* v)
{
	return Scale(v, Dot(v) / v->Dot(v));
}


// object stuff
Vector4 Vector4::GetCopy()
{
	return Vector4(x, y, z, w);
}

std::string Vector4::ToString()
{
	return "(" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "," + std::to_string(w) + ")";
}

void Vector4::SetTo(const Vector4& v)
{
	Initialize(v.x, v.y, v.z, v.w);
}

void Vector4::SetTo(float _x, float _y, float _z, float _w)
{
	Initialize(_x, _y, _z, _w);
}

float Vector4::x1()
{
	return x;
}

float Vector4::x2()
{
	return z;
}

float Vector4::y1()
{
	return y;
}

float Vector4::y2()
{
	return w;
}

Vector2 Vector4::p1()
{
	return Vector2(x, y);
}

Vector2 Vector4::p2()
{
	return Vector2(z, w);
}