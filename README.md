<p align="center">
  <a href="" rel="noopener">
 <img width=200px height=200px src="https://i.imgur.com/6wj0hh6.jpg" alt="Project logo"></a>
</p>

<h3 align="center">TCC - Engenharia da Computação</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![GitHub Issues](https://img.shields.io/github/issues/LeonardoBagio/TCC.svg)](https://github.com/LeonardoBagio/TCC/issues)
[![GitHub Pull Requests](https://img.shields.io/github/issues-pr/LeonardoBagio/TCC.svg)](https://github.com/LeonardoBagio/TCC/pulls)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](/LICENSE)

</div>

## 📝 Conteúdo

- [Sobre](#sobre)
- [Desenvolvimento](#desenvolvimento)
- [Pacotes](#pacote)
- [Autores](#autores)

## 🧐 Sobre <a name = "sobre"></a>

Este projeto foi criado como estudo de caso para conclusão de curso de Engenharia da Computação na faculdade SATC, o objetivo é realizar um estudo e apontar as vantagens e desvantagens no desenvolvimento de um protótipo utilizando controle em malha aberta e fechada.

## 🎈 Pacotes <a name="pacote"></a>

* Para melhor organização, foi alocado todas variáveis de configuração no seguinte arquivo - [Configuracao.h](src\parametro\Configuracao.h)
* Foi separado o sistema em diferentes tarefas utilizando RTOS - Envio informação, hibernação, malha aberta, malha fechada
	* Envio de informação está alocado no [main.cpp](src\main.cpp)
	* Hibernação está alocado no [main.cpp](src\main.cpp)
	* Sistema de malha aberta está alocado no [sistemaPorTempo.h](src\subSistema\sistemaPorTempo.h)
	* Sistema de malha fechada está alocado no [sistemaPorSensor.h](src\subSistema\sistemaPorSensor.h)

## 🚀 Desenvolvimento <a name = "desenvolvimento"></a>

* Foi utilizado vsCode para desenvolvimento junto com [PlatformIO](https://platformio.org/)

## ✍️ Autores <a name = "autores"></a>

- [@LeonardoBagio](https://github.com/LeonardoBagio)
- [@vagner-rodrigues](https://github.com/vagner-rodrigues)