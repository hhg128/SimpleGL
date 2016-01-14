#include "stdafx.h"
#include "ObjectManager.h"
#include "Object.h"


namespace SimpleGL
{
	INT64 ObjectIdGenerator::m_nId = 0;

	ObjectManager::ObjectManager()
	{
	}


	ObjectManager::~ObjectManager()
	{
	}

	Object* ObjectManager::CreateObject(const INT64 nObjectId)
	{
		Object* pObject = new Object;
		AddObejct(nObjectId, pObject);
		return pObject;
	}

	Object* ObjectManager::CreateObject(void)
	{
		Object* pObject = new Object;
		pObject->Initialize();
		AddObejct(ObjectIdGenerator::Generate(), pObject);
		return pObject;
	}

	void ObjectManager::Tick()
	{
		for (auto iter = ObjectMap.begin(); iter != ObjectMap.end(); ++iter)
		{
			iter->second->Tick();
		}
	}

	void ObjectManager::Render()
	{
		for (auto iter = ObjectMap.begin(); iter != ObjectMap.end(); ++iter)
		{
			iter->second->Render();
		}
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