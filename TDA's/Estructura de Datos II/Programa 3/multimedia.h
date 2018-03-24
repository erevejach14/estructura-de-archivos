class Multimedia{
	 private:
	 	char* URL;
	 	char* name;
	 	char* date;

	 	char posi[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','w','x','y','z'};

	 public:
	 	Multimedia();
	 	~Multimedia();
	 	
	 	char* getURL();
	 	void setURL(char*);
	 	char* getName();
	 	void setName(char*);
	 	char* getDate();
	 	void setDate(char*);

	 	bool comprubName(char*);

	 	bool posiblesExt();

 }; 