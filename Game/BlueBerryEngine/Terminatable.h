#ifndef TERMINATABLE_H
#define TERMINATABLE_H



class Terminatable
{
protected:
	bool m_bMarkedForTermination;

	typedef void (*ReturnToFinalManagerFnc)(Terminatable*);
	ReturnToFinalManagerFnc FinalMan;

public:
	Terminatable(void);
	virtual ~Terminatable(void);

	// General Methods
	virtual void Terminate();
	void MarkForTermination();
	void SetFinalManagerReturnFnc(ReturnToFinalManagerFnc f);
	

private:

};
#endif