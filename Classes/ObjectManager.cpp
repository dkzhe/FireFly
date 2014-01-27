#include "ObjectManager.h"

static ObjectManager * g_pObjectManager=NULL;
ObjectManager::ObjectManager()
{
	m_Sprite=new CCSprite *[totalSprite];
	for (int i=0;i<totalSprite;i++)
	{
		m_Sprite[i]=NULL;
	}

	m_Array=new CCArray *[totalArray];
	for (int i=0;i<totalArray;i++)
	{
		m_Array[i]=NULL;
	}
}

ObjectManager::~ObjectManager()
{
	for (int i=0;i<totalSprite;i++)
	{
		CC_SAFE_DELETE(m_Sprite[i]);
	}
	CC_SAFE_DELETE_ARRAY(m_Sprite);

	for (int i=0;i<totalArray;i++)
	{
		CC_SAFE_DELETE_ARRAY(m_Array[i]);
	}
	CC_SAFE_DELETE_ARRAY(m_Array);
}

ObjectManager* ObjectManager::sharedObjectManager()
{
	if (NULL==g_pObjectManager)
	{
		g_pObjectManager=new ObjectManager;
	}
	return g_pObjectManager;
}

void ObjectManager::addObject(AllSprite num,CCSprite * sprite)
{
	if (NULL==m_Sprite[num])
	{
		m_Sprite[num]=sprite;
	}
}

void ObjectManager::addObject(AllArray num,CCArray * arr)
{
	if (NULL==m_Array[num])
	{
		m_Array[num]=arr;
	}
}

CCSprite * ObjectManager::Find(AllSprite num)
{
	if (NULL!=m_Sprite[num])
	{
		return m_Sprite[num];
	}
	return NULL;
}

CCArray *ObjectManager::Find(AllArray num)
{
	if (NULL!=m_Array[num])
	{
		return m_Array[num];
	}
	return NULL;
}