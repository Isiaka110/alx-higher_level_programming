#include <Python.h>

void print_python_list_info(PyObject *p)
{
    /*PyListObject *list;*/
    size_t size;
    PyObject *item;

    /* Check if the object is a PyListObject */
    if (!PyList_Check(p)) {
        printf("[-] It is not a Python list\n");
        return;
    }

    /* Get the size of the list */
    size = PyList_Size(p);

    /* Print list info */
    printf("[*] Size of the Python List = %zu\n", size);
    printf("[*] Python List Object Type: ");

    /* Get the first item for type check (assuming all elements have the same type) */
    item = PyList_GetItem(p, 0);

    /* Check if the item is NULL (empty list or error) */
    if (item == NULL) {
        printf("[ERROR] Failed to get list item\n");
        return;
    }

    /* Print the type of the first item */
    printf("%s\n", Py_TYPE(item)->tp_name);
}

