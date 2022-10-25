<h1 align="center">VTSEd</h1>

<p align="center">
🧙‍♂️ Una libreria che migliora la tua applicazione console C++
</p>

![Banner](./assets/banner.png)



# Indice

- [Funzionalità](#funzionalità)
- [Documentazione](./DOCS.md)
- [Esempi](#esempi)
- [Autore](#autore)
- [Licenza](#licenza)



# Funzionalità

- Console ([`console.hpp`](./vtsed/console.hpp))
- Controlli ([`controls.hpp`](./vtsed/controls.hpp))
- VTS ([`vts.hpp`](./vtsed/vts.hpp))



# Esempi

## Controllo `ListBox`

```cpp
#include "vtsed.hpp"
using namespace vtsed;
```

```cpp
string options[] = {
    "---------",
    " Play    ",
    " Options ",
    " About   ",
    "---------",
    " Quit    ",
    "---------",
};

bool optionsState[] = {
    false,
    true,
    true,
    true,
    false,
    true,
    false,
};

listBox myListBox;

myListBox.setOptions(options);
myListBox.setOptionsState(optionsState);
myListBox.setSelectedOption(1);
myListBox.setOptionsCount(7);

while (myListBox.call() != 5);
```

![ListBox](./assets/listbox.png)



## Controllo `CheckListBox`

```cpp
#include "vtsed.hpp"
using namespace vtsed;
```

```cpp
string options[] = {
    "---------",
    " Apples  ",
    " Bananas ",
    " Oranges ",
    " Peaches ",
    " Kiwi    ",
    "---------",
};

bool optionsState[] = {
    false,
    true,
    true,
    true,
    true,
    true,
    false,
};

int selectedOptions[] = {
    0,
    1,
    0,
    1,
    0,
    0,
    0,
};

checkListBox myCheckListBox;

myCheckListBox.setOptions(options);
myCheckListBox.setOptionsState(optionsState);
myCheckListBox.setSelectedOptions(selectedOptions);
myCheckListBox.setOptionsCount(7);

myCheckListBox.call();
```

![CheckListBox](./assets/checklistbox.png)



# Autore

- [Realluke](https://github.com/reallukee/)



# Licenza

Questo progetto è sotto licenza [MIT](./LICENSE).
