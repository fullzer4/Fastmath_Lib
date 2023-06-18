import { exec } from 'child_process';
import os from 'os';
import { archInstall, ubuntuInstall } from './linux.js';

if (os.platform() === 'win32') {

} else if(os.platform() === 'darwin') {
  
} else if (os.platform() === 'linux') {
  const checkDistroCommand = `
    if [ -f /etc/os-release ]; then
      source /etc/os-release
      echo $ID
    if [ -f /etc/lsb-release ]; then
      source /etc/lsb-release
      echo $DISTRIB_ID
    else
      echo "Distribuição do Linux não suportada."
    fi
  `;
  exec(checkDistroCommand, (error, stdout) => {
    const distro = stdout.trim();

    console.log(distro)

    if (distro === 'ubuntu' || distro === 'Ubuntu') {
      console.log("verificando dependencias")
      exec(`${ubuntuInstall}`, (error, stdout) => {
        if (error) {
          console.log(`Erro ao instalar: ${error}`)
          return
        }
        console.log("instalado com sucesso")
      })
    }else if (distro === 'arch') {
      console.log("verificando dependencias")
      exec(`${archInstall}`, (error, stdout) => {
        if (error) {
          console.log(`Erro ao instalar: ${error}`)
          return
        }
        console.log("instalado com sucesso")
      })
    }
  });
}
