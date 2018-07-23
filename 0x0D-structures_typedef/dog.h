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
void print_dog(struct dog *d);

/**
 * dog_t - Typedef struct dog
 */
typedef struct dog dog_t;
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);


#endif
