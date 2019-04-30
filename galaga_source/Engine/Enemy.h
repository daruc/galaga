#pragma once
#include "InteractiveObject.h"
class Enemy :
	public InteractiveObject
{
public:
	void input() override;
};

