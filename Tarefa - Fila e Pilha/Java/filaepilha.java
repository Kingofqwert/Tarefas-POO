package Java;

class Lista {
    private int[] v;
    private int tam;
    private int tamMax;

    public Lista() {
        tam = 0;
        tamMax = 20;
        v = new int[tamMax];
    }

    public void aumentar() {
        tamMax *= 2;
        int[] aux = new int[tamMax];

        for (int i = 0; i < tam; i++) {
            aux[i] = v[i];
        }

        v = aux;
    }

    public void insere(int x) {
        if (tam == tamMax) {
            aumentar();
        }

        for (int i = tam; i > 0; i--) {
            v[i] = v[i - 1];
        }

        v[0] = x;
        tam++;
    }

    public void remove() {
        if (tam > 0) {
            tam--;
        } else {
            System.out.println("Lista Vazia");
        }
    }

    public int primeiro() {
        if (tam > 0) {
            return v[0];
        } else {
            // Retornar um valor padrão caso a lista esteja vazia
            return -1; // ou outra escolha apropriada
        }
    }

    public int tamanho() {
        return tam;
    }
}

class Pilha extends Lista {
    private int[] v;
    private int tam;
    private int tamMax;

    public void push(int x) {
        if (tam == tamMax) {
            aumentar();
        }

        v[tam] = x;
        tam++;
    }

    public void pop() {
        if (tam > 0) {
            tam--;
        } else {
            System.out.println("Lista Vazia");
        }
    }

    public int primeiro() {
        if (tam > 0) {
            return v[tam - 1];
        } else {
            return -1; 
        }
    }
}

class Fila extends Lista {
    private int[] v;
    private int tam;

    public void remove() {
        if (tam > 0) {
            for (int i = 0; i < tam - 1; i++) {
                v[i] = v[i + 1];
            }
            tam--;
        }
    }

    public int primeiro() {
        if (tam > 0) {
            return v[0];
        } else {
            return -1;
        }
    }
}
