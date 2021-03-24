#ifndef ENGINE_REGISTRYMEMBER
#define ENGINE_REGISTRYMEMBER

#include <memory>
#include <queue>

class RegistryMember
{
public:
	RegistryMember();
	~RegistryMember();

	bool IsFlaggedForRemoval() const;
	void FlagForRemoval(const bool& flag = true);
	void SetDeleteQueue(const std::shared_ptr<std::queue<int>> dQueue);

protected:
	bool isFlaggedForRemoval = false;
	std::shared_ptr<std::queue<int>> deleteQueue = nullptr;
};

#endif
