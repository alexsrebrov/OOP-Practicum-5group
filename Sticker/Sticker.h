#pragma once

enum class Rarity {
	Standard, Silver, Gold, Platinum
};
class Sticker {
	int id;
	char* name;
	int rating;
	Rarity rarity;
	void copyFrom(const Sticker&);
	void moveFrom(Sticker&&);
	void free();
	static int counter;
public:
	friend bool operator==(const Sticker&, const Sticker&);
	friend bool operator<(const Sticker&, const Sticker&);
	Sticker();
	Sticker(const char*, int, Rarity);
	Sticker(const Sticker&);
	Sticker& operator=(const Sticker&);
	~Sticker();
	Sticker(Sticker&&);
	Sticker& operator=(Sticker&&);
	int getRating() const;
	const char* getName() const;
};

