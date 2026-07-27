

# 🚀 Template Base - Unidade Curricular de IoT

Este repositório contém a estrutura base de um projeto PlatformIO para VS Code, pronto para ser utilizado nas aulas práticas da disciplina de Internet das Coisas (IoT).

---

## 📌 Passo a Passo: Como criar sua própria cópia no seu GitHub

Para realizar as atividades e salvar suas alterações, você deve **fazer um Fork** deste repositório original para a sua conta pessoal do GitHub.

### 1️⃣ Criando o Fork
1. Acesse o repositório oficial da disciplina:  
   👉 **[https://github.com/IrineuFrancisco/ProjetoIOT](https://github.com/IrineuFrancisco/ProjetoIOT)**
2. Certifique-se de estar logado com a sua conta do **GitHub**.
3. No canto superior direito da página, clique no botão **Fork** (ou *Criar um fork*).
4. Na tela seguinte, mantenha o nome do repositório e clique no botão verde **Create fork**.
5. Agora você possui uma cópia idêntica deste repositório na sua própria conta (`github.com/SEU-USUARIO/ProjetoIOT`).

---

### 2️⃣ Clonando o Repositório para o seu Computador

1. Abra o **VS Code**.
2. Abra o terminal integrado do VS Code (`Ctrl + '` ou vá no menu superior em `Terminal > Novo Terminal`).
3. Navegue até a pasta onde costuma guardar seus projetos das aulas (exemplo: `cd Documentos`).
4. Execute o comando de clone substituindo `SEU-USUARIO` pelo seu nome de usuário do GitHub:

```bash
git clone [https://github.com/SEU-USUARIO/ProjetoIOT.git](https://github.com/SEU-USUARIO/ProjetoIOT.git)

```

---

### 3️⃣ Abrindo o Projeto no PlatformIO

1. No VS Code, vá em **Arquivo > Abrir Pasta...** (ou `File > Open Folder...`).
2. Selecione a pasta `ProjetoIOT` que você acabou de clonar.
3. Aguarde alguns instantes. A extensão do **PlatformIO** identificará automaticamente o arquivo `platformio.ini` e começará a carregar o ambiente.
* *Nota: Na primeira vez que abrir o projeto, o PlatformIO fará o download automático das ferramentas e dependências. Esse processo pode levar alguns minutos dependendo da conexão.*



---

### 4️⃣ Testando a Compilação e Gravação

Na barra inferior azul do VS Code (ou no menu lateral do **PlatformIO**), utilize os comandos:

* **`✓` (Build):** Compila o código do projeto.
* **`→` (Upload):** Grava o código compilado na placa conectada via USB.
* **`🔌` (Serial Monitor):** Abre o terminal para visualizar as saídas `Serial.print` do dispositivo.

---

### 5️⃣ Salvando e Enviando Suas Alterações (Commit & Push)

Sempre que realizar uma alteração ou concluir um exercício em aula, salve suas modificações na sua conta do GitHub:

```bash
# 1. Adicione os arquivos alterados
git add .

# 2. Crie uma mensagem explicando o que foi feito
git commit -m "feat: exercicio de leitura de sensor concluido"

# 3. Envie para o seu GitHub pessoal
git push origin main

```

```

```