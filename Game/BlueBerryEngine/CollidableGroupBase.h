//-----------------------------------------------------------------
// CollidableGroupBase class
// C++ Header File CollidableGroupBase.h
//-----------------------------------------------------------------
#ifndef COLLIDABLEGROUPBASE_H
#define COLLIDABLEGROUPBASE_H

//-----------------------------------------------------------------
// CollidableGroupBase Class
//-----------------------------------------------------------------
class CollidableGroupBase
{
public:
	//Constructor(s)/Destructors
	CollidableGroupBase(void);
	virtual ~CollidableGroupBase(void);

	// General Methods
	virtual void CallAllTestFunctions();
};
#endif // !COLLIDABLEGROUPBASE_H

