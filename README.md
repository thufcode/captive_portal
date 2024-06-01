<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Captive Portal ESP8266</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            margin: 0;
            padding: 0;
            background-color: #f4f4f4;
            color: #333;
        }
        .container {
            width: 80%;
            margin: auto;
            overflow: hidden;
            padding: 20px;
        }
        h1, h2, h3 {
            color: #0056b3;
        }
        p {
            margin: 10px 0;
        }
        .important {
            font-weight: bold;
            background-color: #ffffcc;
            padding: 5px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Captive Portal</h1>
        <p>Este script foi desenvolvido para ser executado em um dispositivo ESP8266, como o NodeMCU, e tem como objetivo criar um ponto de acesso Wi-Fi falso para capturar credenciais de login. Ele apresenta uma página de login falsa que imita a interface do Facebook para enganar os usuários e capturar suas informações de login.</p>
        
        <h2>Pré-requisitos</h2>
        <p><span class="important">Placa ESP8266 (como NodeMCU)</span><br>
        <span class="important">Arduino IDE configurada para programar ESP8266</span><br>
        Bibliotecas necessárias: EEPROM, DNSServer, ESP8266WiFi, ESP8266WebServer, FS</p>
        
        <h2>Configuração</h2>
        <p>Antes de carregar o script para o dispositivo ESP8266, certifique-se de configurar as seguintes variáveis:</p>
        <ul>
            <li><span class="important">SSID_NAME:</span> Nome da rede Wi-Fi falsa que será criada.</li>
            <li><span class="important">HTTP_PORT e DNS_PORT:</span> Portas para o servidor HTTP e DNS.</li>
            <li><span class="important">apIP e netMask:</span> Configurações de IP e máscara de sub-rede para o ponto de acesso.</li>
        </ul>

        <h2>Funcionamento</h2>
        <p>Quando o dispositivo é ligado, ele cria um ponto de acesso Wi-Fi com o SSID especificado. Os usuários podem se conectar a esta rede Wi-Fi e, ao tentarem acessar a internet, serão redirecionados para uma página de login falsa que imita a interface do Facebook. Ao inserirem suas credenciais (e-mail e senha) na página falsa e clicarem em "Entrar", as informações são capturadas e armazenadas na memória EEPROM do dispositivo.</p>
        
        <h2>Rotas do Servidor Web</h2>
        <p>O script define várias rotas para o servidor web embutido no dispositivo ESP8266:</p>
        <ul>
            <li><span class="important">/:</span> Página de login falsa imitando o Facebook.</li>
            <li><span class="important">/postinfo:</span> Rota para capturar e armazenar as credenciais.</li>
            <li><span class="important">/getinfo:</span> Rota para exibir as credenciais armazenadas.</li>
            <li><span class="important">/deleteinfo:</span> Rota para limpar as credenciais armazenadas.</li>
            <li><span class="important">/credenciais:</span> Página para visualizar as credenciais capturadas.</li>
            <li><span class="important">/admin:</span> Página de administração para configurar o SSID da rede Wi-Fi falsa.</li>
        </ul>

        <h2>Página de Administração</h2>
        <p>A página de administração oferece funcionalidades adicionais para configurar o dispositivo ESP8266 e gerenciar as credenciais capturadas. Esta página pode ser acessada digitando o seguinte endereço no navegador: <span class="important">http://172.0.0.1/admin</span></p>
        
        <h3>Funcionalidades Disponíveis</h3>
        <ul>
            <li><span class="important">Atualizar SSID:</span> Permite ao usuário atualizar o nome da rede Wi-Fi falsa (SSID). Ao inserir o novo SSID na caixa de texto e clicar em "Atualizar SSID", o SSID será alterado e a rede Wi-Fi falsa será reiniciada com o novo nome.</li>
            <li><span class="important">Ver Credenciais:</span> Direciona o usuário para uma página onde ele pode visualizar todas as credenciais capturadas até o momento. As credenciais são exibidas em formato de lista, mostrando o e-mail e a senha associados a cada conjunto capturado.</li>
        </ul>

        <h2>Galeria de Imagens</h2>
        <p><span class="important">Administração Portal</span></p>

        <h2>Considerações de Segurança e Ética</h2>
        <p>Este script é fornecido apenas para fins educacionais e de teste. O uso indevido para capturar informações confidenciais é ilegal e antiético.<br>
        Não é recomendado implantar este script em redes públicas ou sem o consentimento explícito dos usuários.</p>
    </div>
</body>
</html>
