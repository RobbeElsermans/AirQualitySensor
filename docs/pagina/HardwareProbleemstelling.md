# Hardware probleemstelling
### hardware schema & pcb design

<img src="./picture/schema_hardware.png">

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
<td>eigenschap</td>
<td>argument</td>
<td><a target="_blank" href="">link</a></td>
</tr>
<tr>
<td>MQ-135</td>
<td>eigenschap</td>
<td>argument</td>
<td><a target="_blank" href="">link</a></td>
</tr>
<tr>
<td>DHT22</td>
<td>eigenschap</td>
<td>argument</td>
<td><a target="_blank" href="">link</a></td>
</tr>
<tr>
<td>CJMCU-811</td>
<td>eigenschap</td>
<td>argument</td>
<td><a target="_blank" href="">link</a></td>
</tr>
<tr>
<td>GY-NEO6MV2</td>
<td>eigenschap</td>
<td>argument</td>
<td><a target="_blank" href="">link</a></td>
</tr>
<tr>
<td>SDS011</td>
<td>eigenschap</td>
<td>argument</td>
<td><a target="_blank" href="">link</a></td>
</tr>
<tr>
<td>LM35</td>
<td>eigenschap</td>
<td>argument</td>
<td><a target="_blank" href="">link</a></td>
</tr>
<tr>
<td>MHZ19</td>
<td>eigenschap</td>
<td>argument</td>
<td><a target="_blank" href="">link</a></td>
</tr>
</table>

### voeding etc.