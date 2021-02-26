# Hardware probleemstelling
### hardware schema & pcb design

<img src="./picture/schema_hardware.png">

---------------

### microcontroller
<p>We maken gebruik van de ESP32, aangezien deze werkt met de gewone arduino wifi libraries.
Het is mogelijk dat we later naar de ESP12f (ESP8266 familie) overschakelen. Aangezien deze minder verbruiken en minder kosten.</p>
* <a target="_blank" href="https://makeradvisor.com/esp32-vs-esp8266/">Verschil tussen ESP32 & ESP8266</a> 
<img src="./picture/ESP32_Pinout.jpg">

### sensoren
<p>In onze opstelling gaan we CO, CO², luchtvichtigheid, temperatuur, luchtkwaliteit en fijnstof meten. Hiervoor bestaan verschillende soorten sensoren die elk hun eigen voor en nadelen hebben. Voor de eenvoud van de meetingen gaan we er een GPS coördinaat bijplaatsen zodat het makkelijk in kaart gebracht kan worden.</p>
<p>In onderstaande tabel gaan we elk bespreken en beargumenteren waarom ze beter zijn dan anderen, de voordelen, eigenschappen en eventuele tegenhangers. Bij elke module, die we fysiek konden testen, is er een sketch beschikbaar in de repository onder <a target="_blank" href="https://github.com/RobbeElsermans/AirQualitySensor/tree/main/Arduino%20program/onderzoek"><i>Arduino program/onderzoek</i></a>.</p>
</br>
</br>

<table>
<tr>
    <th>Naam</th>
    <th>Eigenschappen</th>
    <th>argumentatie</th>
    <th>website</th>
</tr>
<tr>
    <td>MQ-7</td>
    <td>
        <ul>
            <li><b>CO gas sensor</b></li>
            <li>V<sub>cc</sub> = 5V</li>
            <li>I<sub>max</sub> = 350mA</li>
            <li>analoge uitgang van 0V-5V</li>
            <li>digitale uitgang instelbaar via trim</li>
            <li>voorverwarm tijd: 48 uur</li>
            <li>meetbereik: 20ppm<sup>1</sup>-2000ppm</li>
            <li>leessnelheid = continue</li>
        </ul>
    </td>
    <td>argument</td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/sensoren/mq-7-gas-sensor-module">link</a></td>
</tr>
<tr>
    <td>MQ-135</td>
    <td>        
        <ul>
            <li><b>CO² gas sensor</b></li>
            <li>V<sub>cc</sub> = 5V</li>
            <li>I<sub>max</sub> = 800mW</li>
            <li>analoge uitgang van 0V-5V</li>
            <li>digitale uitgang instelbaar via trim</li>
            <li>voorverwarm tijd: 24 uur</li>
            <li>meetbereik: 10ppm-200ppm</li>
            <li>leessnelheid = continue</li>
        </ul>
    </td>
    <td>argument</td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/sensoren/mq-135-gas-sensor-module">link</a></td>
</tr>
<tr>
    <td>DHT22</td>
    <td>        
        <ul>
            <li><b>Temperatuur & luchtvochtigheid</b></li>
            <li>V<sub>cc</sub> = 3.3V-5V</li>
            <li>I<sub>max</sub> = 1.5mA</li>
            <li><a target="_blank" href="https://en.wikipedia.org/wiki/1-Wire">OneWire</a> protocol 3.3V-5V</li>
            <li>meetbereik temperatuur: -40°C ~ +80°C - 0.5°C afwijking</li>
            <li>meetbereik luchtvochtigheid: 0% ~ 100% - 2% afwijking</li>
            <li>leessnelheid = 2s of meer</li>
        </ul>
    </td>
    <td>argument</td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/sensoren/dht22-thermometer-temperatuur-en-vochtigheids-sensor">link</a></td>
</tr>
<tr>
    <td>CCS811</td>
    <td>
        <ul>
            <li><b>eCO² en eTVOC<sup>2</sup></b></li>
            <li>V<sub>cc</sub> = 1.8V-3.3V</li>
            <li>I<sub>max</sub> = 54mA</li>
            <li><a target="_blank" href="https://en.wikipedia.org/wiki/I%C2%B2C">I²C</a> protocol 3.3V</li>
            <li>meetbereik temperatuur: -40°C ~ +85°C</li>
            <li>meetbereik luchtvochtigheid: 10% ~ 95% </li>
            <li>meetbereik eCO²: 400ppm - 32768ppm</li>
            <li>meetbereik eTVOC: 0ppb - 29206ppb</li>
            <li>leessnelheid = 100kHz (0.01ms)</li>
        </ul>
    </td>
    <td>argument</td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/sensoren/ccs811-luchtkwaliteit-sensor">link</a></td>
</tr>
<tr>
    <td>GY-NEO6MV2</td>
    <td>
        <ul>
            <li><b>GPS module</b></li>
            <li>V<sub>cc</sub> = 3.3V-5V</li>
            <li>I<sub>max</sub> = 67mA</li>
            <li><a target="_blank" href="https://en.wikipedia.org/wiki/Universal_asynchronous_receiver-transmitter">UART</a> protocol 3.3V</li>
            <li>baudrate: 9600</li>
            <li>leessnelheid = 1Hz (1s)</li>
        </ul>
    </td>
    <td>argument</td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/communicatie/gps/gy-neo6mv2-gps-module">link</a></td>
</tr>
<tr>
    <td>SDS011</td>
    <td>
        <ul>
            <li><b>fijnstof sensor</b></li>
            <li>V<sub>cc</sub> = 5V</li>
            <li>I<sub>max</sub> = 200mA</li>
            <li><a target="_blank" href="https://en.wikipedia.org/wiki/Universal_asynchronous_receiver-transmitter">UART</a> protocol 3.3V</li>
            <li>baudrate: 9600</li>
            <li>Meetbereik PM2.5<sup>3</sup> & PM10<sup>4</sup>: 0μg/m3 ~ 999.9 μg/m3</li>
            <li>meetbereik luchtvochtigheid: 10% ~ 95% </li>
            <li>leessnelheid = 1Hz (1s)</li>
        </ul>
    </td>
    <td>argument</td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/sensoren/nova-sds011-hoge-precisie-laser-stofsensor">link</a></td>
</tr>
<tr>
    <td>LM35</td>
    <td>eigenschap</td>
    <td>argument</td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/sensoren/lm35-to-92-thermometer-temperatuur-sensor">link</a></td>
</tr>
<tr>
    <td>MHZ19</td>
    <td>eigenschap</td>
    <td>argument</td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/sensoren/winsen-mh-z19c-co2-sensor-met-kabel">link</a></td>
</tr>
<tr>
    <td>BME280</td>
    <td>eigenschap</td>
    <td>argument</td>
    <td><a target="_blank" href="https://www.tinytronics.nl/shop/nl/sensoren/temperatuur-lucht-vochtigheid/bme280-digitale-barometer-druk-en-vochtigheid-sensor-module">link</a></td>
</tr>
</table>

<div style="font-size: 75%; line-height: 0; position: relative; vertical-align: baseline; top: -0.5em">
<p>ppm<sup>1</sup>: Parts per million (ppm) oftewel delen per miljoen is een maat voor concentratie. <a target="_blank" href="https://nl.wikipedia.org/wiki/Parts_per_million">wikipedia</a></p>
<p>eTVOC<sup>2</sup>: alle vluchtige organische stoffen (zoals Benzeen, Tolueen, Glycolen en Terpenen). <a target="_blank" href="https://www.ecolucht.nl/formaldehydemeter/tvoc.html#:~:text=Een%20TVOC%20meting%20analyseert%20niet,Tolueen%2C%20Glycolen%20en%20Terpenen).">ecolucht.nl</a> </p>
<p>PM2.5<sup>3</sup>: zwevende stof met diameter kleiner dan 2.5µm<a target="_blank" href="https://www.irceline.be/nl/documentatie/faq/wat-is-fijnstof">irceline.be</a></p>
<p>PM10<sup>4</sup>: zwevende stof met diameter kleiner dan 10µm<a target="_blank" href="https://www.irceline.be/nl/documentatie/faq/wat-is-fijnstof">irceline.be</a></p>
<div>

### voeding etc.