#ifndef SPACEGAME_SPACESHIP
#define SPACEGAME_SPACESHIP

#include "Engine/Graphics/Spritesheet.h"
#include "Engine/Math/Vector2.h"
#include "Engine/Math/IVector2.h"
#include "Engine/Entities/Player.h"
#include "Engine/Components/ConstantParticleEmitter.h"
#include "Engine/Components/HitboxedObject.h"

class Spaceship : public Player, public ConstantParticleEmitter
{

public:
	Spaceship();
	~Spaceship();
	Spaceship(const Spaceship& other) : Spaceship() {};
	Spaceship& operator=(const Spaceship& other) { return *this; };

	void Move() override;
	void Shoot();
	bool IsHit();
	void Respawn();
	void Render() const override;
	void DebugPhysics() const override;
	Vector2 GetPos() const;
	
private:
	int numOfLives = 3;

	float shotCooldownMax = 0.5;
	float shotCooldown = 0;

	Vector2 vel = Vector2::ZERO;

	const IVector2 LEFT = IVector2(0, 0);
	const IVector2 STRAIGHT = IVector2(1, 0);
	const IVector2 RIGHT = IVector2(2, 0);

	Spaceship* clone_impl() const override {
		std::cout << "Should not be cloning the Spaceship!!" << std::endl;
		return new Spaceship(*this);
	}
};

#endif