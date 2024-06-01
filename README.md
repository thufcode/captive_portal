# **Captive Portal**

Este script foi desenvolvido para ser executado em um dispositivo ESP8266, como o NodeMCU, e tem como objetivo criar um ponto de acesso Wi-Fi falso para capturar credenciais de login. Ele apresenta uma página de login falsa que imita a interface do Facebook para enganar os usuários e capturar suas informações de login.

## **Pré-requisitos**
- Placa ESP8266 (como NodeMCU)
- Arduino IDE configurada para programar ESP8266
- Bibliotecas necessárias: EEPROM, DNSServer, ESP8266WiFi, ESP8266WebServer, FS
    
## **Configuração**
Antes de carregar o script para o dispositivo ESP8266, certifique-se de configurar as seguintes variáveis:
- SSID_NAME: Nome da rede Wi-Fi falsa que será criada.
- HTTP_PORT e DNS_PORT: Portas para o servidor HTTP e DNS.
- apIP e netMask: Configurações de IP e máscara de sub-rede para o ponto de acesso.
    
## **Funcionamento**
Quando o dispositivo é ligado, ele cria um ponto de acesso Wi-Fi com o SSID especificado. Os usuários podem se conectar a esta rede Wi-Fi e, ao tentarem acessar a internet, serão redirecionados para uma página de login falsa que imita a interface do Facebook.
Ao inserirem suas credenciais (e-mail e senha) na página falsa e clicarem em "Entrar", as informações são capturadas e armazenadas na memória EEPROM do dispositivo.

## **Rotas do Servidor Web**
O script define várias rotas para o servidor web embutido no dispositivo ESP8266:
- /: Página de login falsa imitando o Facebook.
- /postinfo: Rota para capturar e armazenar as credenciais.
- /getinfo: Rota para exibir as credenciais armazenadas.
- /deleteinfo: Rota para limpar as credenciais armazenadas.
- /credenciais: Página para visualizar as credenciais capturadas.
- /admin: Página de administração para configurar o SSID da rede Wi-Fi falsa.
    
## **Página de Administração**
A página de administração oferece funcionalidades adicionais para configurar o dispositivo ESP8266 e gerenciar as credenciais capturadas. Esta página pode ser acessada digitando o seguinte endereço no navegador: http://172.0.0.1/admin
### Funcionalidades Disponíveis
1. **Atualizar SSID:** Permite ao usuário atualizar o nome da rede Wi-Fi falsa (SSID). Ao inserir o novo SSID na caixa de texto e clicar em "Atualizar SSID", o SSID será alterado e a rede Wi-Fi falsa será reiniciada com o novo nome.
2. **Ver Credenciais:** Direciona o usuário para uma página onde ele pode visualizar todas as credenciais capturadas até o momento. As credenciais são exibidas em formato de lista, mostrando o e-mail e a senha associados a cada conjunto capturado.

<h2>Galeria de Imagens</h2>

<div class="container">
  <div class="imagem">
    <h3>Administração Portal</h3>
  <div class="imagem">
    <img src="https://github.com/thufcode/captive_portal/assets/36115813/b3f3215f-7fe3-427d-93d3-3a82ace0a35f" alt="Credenciais do Portal">
  </div>
</div>

</body>
</html>


## **Considerações de Segurança e Ética**
- Este script é fornecido apenas para fins educacionais e de teste. O uso indevido para capturar informações confidenciais é ilegal e antiético.
- Não é recomendado implantar este script em redes públicas ou sem o consentimento explícito dos usuários.
