# FMR 2024-Conceicao


### [Edital](https://docs.google.com/document/d/1GYI4jlVt_yt1teEoTLcq23WhZJW5KBZPciDaXZczRek/edit)


## Missões concluidas:
- [ ] Missão Aliança
- [ ] Missão Cidade Alerta Pt 1
- [ ] Missão Cidade Alerta Pt 2
- [ ] Missão Construindo Conexões



## Utilitarios
[NXC](https://bricxcc.sourceforge.net/nbc/nxcdoc/NXC_tutorial.pdf) 
[NXC Guide](https://bricxcc.sourceforge.net/nbc/nxcdoc/nxcapi/index.html)
[NXC Instalador e etc](https://bricxcc.sourceforge.net/)

### Para usar o Visual Studio:

Instalar o Visual Studio:

Se ainda não o fez, baixe e instale o Visual Studio Community Edition (ou qualquer versão adequada).
Instalar o BricxCC e o NXC:

Baixe e instale o BricxCC, pois você precisará dele para compilar o código NXC.
Certifique-se de que o NXC está instalado e configurado no seu sistema.
Configurar o Visual Studio:

Abra o Visual Studio e crie um novo projeto de tipo “Console Application” (Aplicação de Console).
No Visual Studio, você não pode compilar diretamente NXC, então você usará o Visual Studio apenas como um editor de código.
Configurar o Build Process:

Você precisa criar uma configuração de Build personalizada para chamar o compilador NXC a partir do Visual Studio.

No menu “Project”, selecione “Properties” (Propriedades).

Vá até “Configuration Properties” > “Build Events” > “Post-Build Event”.

Configure o Post-Build Event para chamar o compilador NXC (nxc.exe). O comando pode se parecer com:

"C:\Caminho\Para\nxc.exe" "$(ProjectDir)$(ProjectName).nxc" -o "$(TargetDir)$(TargetName).rxe"
Certifique-se de ajustar os caminhos para o local do compilador NXC e os arquivos do projeto.

Editar e Compilar Código NXC:

Escreva o código NXC no Visual Studio.
Salve o arquivo com a extensão .nxc.
Após salvar, o Visual Studio chamará o compilador NXC automaticamente como parte do processo de Build.
Transferir e Executar:

Depois de compilar, você precisará transferir o arquivo .rxe gerado para o NXT usando o BricxCC ou qualquer outro software de gerenciamento de NXT.
