#include "stdafx.h"
#include "ObjectManager.h"
#include "Object.h"


namespace SimpleGL
{
	ObjectManager::ObjectManager()
	{
	}


	ObjectManager::~ObjectManager()
	{
	}

	void ObjectManager::CreateObject(const INT64 nObjectId)
	{
		Object* pObject = new Object;
		AddObejct(nObjectId, pObject);
	}

	void ObjectManager::CreateObject(void)
	{
		Object* pObject = new Object;
		AddObejct(ObjectIdGenerator::Generate(), pObject);
	}

	void ObjectManager::AddObejct(const INT64 nId, class Object* pObject)
	{
		if (pObject)
			ObjectMap.insert(std::pair<INT64, class Object*>(ObjectIdGenerator::Generate(), pObject));
	}

	void ObjectManager::RemoveObject(const INT64 nDelObjectId)
	{
		auto DelObject = ObjectMap.find(nDelObjectId);
		if (DelObject == ObjectMap.end())
		{
			return;
		}

		if (DelObject->second)
		{
			ObjectMap.erase(nDelObjectId);
		}
	}

}