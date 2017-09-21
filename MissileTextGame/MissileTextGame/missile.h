#pragma once

struct missile 
{
};

bool armed;

void arm()//arms or disarms the warheads
{
	if (armed)
	{
		armed = false;
	}
	else
	{
		armed = true;
	}
}

void update()
{

}
