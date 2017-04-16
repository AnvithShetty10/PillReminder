import React, { Component } from 'react';
import {
	AppRegistry,
	View,
	Button,
	Text,
} from 'react-native';
import { SegmentedControls } from 'react-native-radio-buttons';

class PillReminder extends Component {
	clickHandler() {
		fetch('https://anask.xyz/ledger/react-check', {
			method: 'POST',
			headers: {
				'Accept': 'application/json',
				'Content-Type': 'application/json',
			},
			body: JSON.stringify({
				led: this.state.selectedLed,
				time: this.state.selectedTime,
			})
		}).then((response) => response.json())
			.then((responseJson) => {
				this.setState({
					showText: JSON.stringify(responseJson.confirm)
				})
			})
			.catch((error) => {
				console.error(error);
			});
	}

	clickHandlerNow() {
		fetch('https://anask.xyz/ledger/now', {
			method: 'POST',
			headers: {
				'Accept': 'application/json',
				'Content-Type': 'application/json',
			},
			body: JSON.stringify({
				led: this.state.selectedLed,
			})
		}).then((response) => response.json())
			.then((responseJson) => {
				this.setState({
					showText: JSON.stringify(responseJson.confirm)
				})
			})
			.catch((error) => {
				console.error(error);
			});
	}

	constructor() {
		super();
		this.state = { showText: null, selectedTime: 'None', selectedLed: 'None' };

		this.clickHandler = this.clickHandler.bind(this);
		this.clickHandlerNow = this.clickHandlerNow.bind(this);
	}
	render() {
		let timeOptions = [
    		"9 AM",
    		"3 PM",
			"6 PM"
  		];
		let LedOptions = [
			"LED 1",
			"LED 2",
			"LED 3",
			"LED 4",
			"LED 5",
			"LED 6"
		];

  		function setSelectedLed(selectedLed){
			this.setState({selectedLed});
  		}
		function setSelectedTime(selectedTime){
			this.setState({selectedTime});
		}
		let check = this.state.showText ? this.state.showText : "Nothing";
		return (
			<View style={{ padding: 20, flex: 1 }}>
				<SegmentedControls
 	 				options={ LedOptions }
  					onSelection={ setSelectedLed.bind(this) }
  					selectedOption={ this.state.selectedLed }
					//direction="column"
				/>
				<SegmentedControls
 	 				options={ timeOptions }
  					onSelection={ setSelectedTime.bind(this) }
  					selectedOption={ this.state.selectedTime }
				/>
				<Text>Selected LED: {this.state.selectedLed}</Text>
				<Text>Select Time: {this.state.selectedTime}</Text>
				<Button onPress={this.clickHandler} title="Proceed" color="#841584"/>
				<Text>{check}</Text>
				<Button onPress={this.clickHandlerNow} title="Send Immediately" color="#841584"/>
			</View>
		);
	}
}

AppRegistry.registerComponent('PillReminder', () => PillReminder);
