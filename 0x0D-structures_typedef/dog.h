#ifndef _DOG_
#define _DOG_

/**
 * struct dog - Store data of name, age and owner of dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 *
 * Description: No
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif
