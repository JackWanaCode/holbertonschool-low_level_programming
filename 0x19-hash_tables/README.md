# 0x19. C - Hash tables

## Target

- What is a hash function

- What makes a good hash function

- What is a hash table, how do they work and how to use them

- What is a collision and what are the main ways of dealing with collisions in the context of a hash table

- What are the advantages and drawbacks of using hash tables

- What are the most common use cases of hash tables

## 0. >>> ht = {}

Write a function that creates a hash table.

Prototype: hash_table_t *hash_table_create(unsigned long int size);

 - where size is the size of the array

Returns a pointer to the newly created hash table

If something went wrong, your function should return NULL

File: 0-hash_table_create.c

## 1. djb2

Write a hash function implementing the djb2 algorithm.

Prototype: unsigned long int hash_djb2(const unsigned char *str);

You are allowed to copy and paste the function from this page

File: 1-djb2.c

## 2. key -> index

Write a function that gives you the index of a key.

Prototype: unsigned long int key_index(const unsigned char *key, unsigned long int size);

 - where key is the key

 - and size is the size of the array of the hash table

This function should use the hash_djb2 function that you wrote earlier

Returns the index at which the key/value pair should be stored in the array of the hash table

You will have to use this hash function for all the next tasks

File: 2-key_index.c

## 3. >>> ht['betty'] = 'holberton'

Write a function that adds an element to the hash table.

Prototype: int hash_table_set(hash_table_t *ht, const char *key, const char *value);

 - Where ht is the hash table you want to add or update the key/value to key is the key. key can not be an empty string

 - and value is the value associated with the key. value must be duplicated. value can be an empty string

Returns: 1 if it succeeded, 0 otherwise

In case of collision, add the new node at the beginning of the list

File: 3-hash_table_set.c

## 4. >>> ht['betty']

Write a function that retrieves a value associated with a key.

Prototype: char *hash_table_get(const hash_table_t *ht, const char *key);

 - where ht is the hash table you want to look into
and key is the key you are looking for

 - Returns the value associated with the element, or NULL if key couldn’t be found

File: 4-hash_table_get.c

## 5. >>> print(ht)

Write a function that prints a hash table.

Prototype: void hash_table_print(const hash_table_t *ht);

 - where ht is the hash table

You should print the key/value in the order that they appear in the array of hash table

 - Order: array, list

 - Format: see example

If ht is NULL, don’t print anything

File: 5-hash_table_print.c

## 6. >>> del ht

Write a function that deletes a hash table.

Prototype: void hash_table_delete(hash_table_t *ht);

 - where ht is the hash table

File: 6-hash_table_delete.c

## 7. $ht['Betty'] = 'Holberton'

Before you continue, please take a moment to think about it: how you would implement it if you were asked to during an interview or a job. What data structures would you use? How would it work?

For this task, please:

 - Read PHP Internals Book: HashTable

 - Use the same hash function

 - Use these data structures:

Rewrite the previous functions using these data structures:

 - shash_table_t *shash_table_create(unsigned long int size);

 - int shash_table_set(shash_table_t *ht, const char *key, const char *value);

   - The key/value pair should be inserted in the sorted list at the right place

   - Note that here we do not want to do exactly like PHP: we want to create a sorted linked list, by key (sorted on ASCII value), that we can print by traversing it. See example.

 - char *shash_table_get(const shash_table_t *ht, const char *key);

 - void shash_table_print(const shash_table_t *ht);

   - Should print the hash table using the sorted linked list

 - void shash_table_print_rev(const shash_table_t *ht);

   - Should print the hash tables key/value pairs in reverse order using the sorted linked list

 - void shash_table_delete(shash_table_t *ht);

 - You are allowed to have more than 5 functions in your file
