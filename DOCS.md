# Documentazione

# Controlli Base

## Controllo `SingleControl`

> ⚠️ Questo controllo ha lo scopo di fornire una base comune a tutti i controlli dinamici a restituzione singola.
> Non presenta una interfaccia grafica.

### Chiamate

- `Call`
- `Draw` (Da Definire)
- `Loop`

### Eventi

### Comandi

- `Up Command` Seleziona la prima opzione abilitata disponibile precedente alla selezione corrente.
Se la selezione corrente è la prima opzione abilitata seleziona la prima opzione abilitata a partire dal fondo.
Questo comando viene invocato quando l'utente preme i tasti <kbd>W</kbd> o <kbd>Up Arrow</kbd>.
- `Down Command` Seleziona la prima opzione abilitata disponibile successiva alla selezione corrente.
Se la selezione corrente è l'ultima opzione abilitata seleziona la prima opzione abilitata a partire dall'alto.
Questo comando viene invocato quando l'utente preme i tasti <kbd>S</kbd> o <kbd>Down Arrow</kbd>.
- `Top Command` Seleziona la prima opzione abilitata a partire dall'alto.
Questo comando viene invocato quando l'utente preme i tasti <kbd>T</kbd> o <kbd>Page Up</kbd>.
- `Bottom Command` Seleziona la prima opzione abilitata a partire dal fondo.
Questo comando viene invocato quando l'utente preme i tasti <kbd>B</kbd> o <kbd>Page Down</kbd>.
- `Select Command` Imposta l'opzione corrente come selezionata.
Questo comando viene invocato quando l'utente preme i tasti <kbd>D</kbd> o <kbd>Right Arrow</kbd>.
- `Deselect Command` Imposta l'opzione corrente come deselezionata.
Questo comando viene invocato quando l'utente preme i tasti <kbd>A</kbd> o <kbd>Left Arrow</kbd>.
- `Action Command` Restituisce all'entità chiamate l'indice corrispondente alla selezione.
Questo comando viene invocato quando l'utente preme i tasti <kbd>X</kbd> o <kbd>Enter</kbd>.



## Controllo `MultiControl`

> ⚠️ Questo controllo ha lo scopo di fornire una base comune a tutti i controlli dinamici a restituzione multipla.
> Non presenta una interfaccia grafica.

### Chiamate

- `Call`
- `Draw` (Da Definire)
- `Loop`

### Eventi

### Comandi

- `Up Command` Seleziona la prima opzione abilitata disponibile precedente alla selezione corrente.
Se la selezione corrente è la prima opzione abilitata seleziona la prima opzione abilitata a partire dal fondo.
Questo comando viene invocato quando l'utente preme i tasti <kbd>W</kbd> o <kbd>Up Arrow</kbd>.
- `Down Command` Seleziona la prima opzione abilitata disponibile successiva alla selezione corrente.
Se la selezione corrente è l'ultima opzione abilitata seleziona la prima opzione abilitata a partire dall'alto.
Questo comando viene invocato quando l'utente preme i tasti <kbd>S</kbd> o <kbd>Down Arrow</kbd>.
- `Top Command` Seleziona la prima opzione abilitata a partire dall'alto.
Questo comando viene invocato quando l'utente preme i tasti <kbd>T</kbd> o <kbd>Page Up</kbd>.
- `Bottom Command` Seleziona la prima opzione abilitata a partire dal fondo.
Questo comando viene invocato quando l'utente preme i tasti <kbd>B</kbd> o <kbd>Page Down</kbd>.
- `Select Command` Imposta l'opzione corrente come selezionata.
Questo comando viene invocato quando l'utente preme i tasti <kbd>D</kbd> o <kbd>Right Arrow</kbd>.
- `Deselect Command` Imposta l'opzione corrente come deselezionata.
Questo comando viene invocato quando l'utente preme i tasti <kbd>A</kbd> o <kbd>Left Arrow</kbd>.
- `Action Command` Restituisce all'entità chiamate l'indice corrispondente alla selezione.
Questo comando viene invocato quando l'utente preme i tasti <kbd>X</kbd> o <kbd>Enter</kbd>.



# Controlli Derivati

## Controllo `ListBox`

Il controllo `ListBox` è basato sul controllo `SingleControl`.

![ListBox](./assets/listbox.png)

### Comandi

Eredita i comandi da `SingleControl`.



## Controllo `CheckListBox`

Il controllo `CheckListBox` è basato sul controllo `MultiControl`.

![CheckListBox](./assets/checklistbox.png)

### Comandi

Eredita i comandi da `MultiControl`.
