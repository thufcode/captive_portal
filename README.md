# Captive Portal

Este script foi desenvolvido para ser executado em um dispositivo ESP8266, como o NodeMCU, e tem como objetivo criar um ponto de acesso Wi-Fi falso para capturar credenciais de login. Ele apresenta uma página de login falsa que imita a interface do Facebook para enganar os usuários e capturar suas informações de login.

## Pré-requisitos

**Placa ESP8266 (como NodeMCU)**  
**Arduino IDE configurada para programar ESP8266**  
Bibliotecas necessárias: EEPROM, DNSServer, ESP8266WiFi, ESP8266WebServer, FS

## Instalar Drivers

| ![CP210x](https://github.com/thufcode/captive_portal/assets/36115813/0a9d8c0b-191e-43a9-bd0e-8801d7895672) | ![CH34x](https://github.com/thufcode/captive_portal/assets/36115813/a0c204c8-074d-49e7-a6f8-3fe060cbf713) |
|:---:|:---:|
| [CP210x Drivers](https://github.com/samdenty99/Wi-PWN/tree/master/drivers/CP210x) | [CH34x Drivers](https://github.com/samdenty99/Wi-PWN/tree/master/drivers/CH34x) |

## Configuração

Antes de carregar o script para o dispositivo ESP8266, certifique-se de configurar as seguintes variáveis:

- **SSID_NAME:** Nome da rede Wi-Fi falsa que será criada.
- **HTTP_PORT e DNS_PORT:** Portas para o servidor HTTP e DNS.
- **apIP e netMask:** Configurações de IP e máscara de sub-rede para o ponto de acesso.

## Funcionamento

Quando o dispositivo é ligado, ele cria um ponto de acesso Wi-Fi com o SSID especificado. Os usuários podem se conectar a esta rede Wi-Fi e, ao tentarem acessar a internet, serão redirecionados para uma página de login falsa que imita a interface do Facebook. Ao inserirem suas credenciais (e-mail e senha) na página falsa e clicarem em "Entrar", as informações são capturadas e armazenadas na memória EEPROM do dispositivo.

## Rotas do Servidor Web

O script define várias rotas para o servidor web embutido no dispositivo ESP8266:

- **/** Página de login falsa imitando o Facebook.
- **/postinfo** Rota para capturar e armazenar as credenciais.
- **/getinfo** Rota para exibir as credenciais armazenadas.
- **/deleteinfo** Rota para limpar as credenciais armazenadas.
- **/credenciais** Página para visualizar as credenciais capturadas.
- **/admin** Página de administração para configurar o SSID da rede Wi-Fi falsa.

## Página de Administração

A página de administração oferece funcionalidades adicionais para configurar o dispositivo ESP8266 e gerenciar as credenciais capturadas. Esta página pode ser acessada digitando o seguinte endereço no navegador: **http://172.0.0.1/admin**

### Funcionalidades Disponíveis

- **Atualizar SSID:** Permite ao usuário atualizar o nome da rede Wi-Fi falsa (SSID). Ao inserir o novo SSID na caixa de texto e clicar em "Atualizar SSID", o SSID será alterado e a rede Wi-Fi falsa será reiniciada com o novo nome.
- **Ver Credenciais:** Direciona o usuário para uma página onde ele pode visualizar todas as credenciais capturadas até o momento. As credenciais são exibidas em formato de lista, mostrando o e-mail e a senha associados a cada conjunto capturado.

## Galeria de Imagens

| ![Administração Portal](https://github.com/thufcode/captive_portal/assets/36115813/6a2bd40f-d3f1-4507-b5b9-d9ed381f2530) | ![Credenciais Portal](https://github.com/thufcode/captive_portal/assets/36115813/8001b748-d8fa-4901-a0c3-8dba8068d521) | ![Login Fake Facebook](https://github.com/thufcode/captive_portal/assets/36115813/21617c00-9ffa-42ba-928f-fdc870cfdc5f) |
|:---:|:---:|:---:|
| Administração Portal | Credenciais Portal | Login Fake Facebook |

## Considerações de Segurança e Ética

Este script é fornecido apenas para fins educacionais e de teste. O uso indevido para capturar informações confidenciais é ilegal e antiético.  
Não é recomendado implantar este script em redes públicas ou sem o consentimento explícito dos usuários.
