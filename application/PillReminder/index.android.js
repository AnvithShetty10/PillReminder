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
		fetch('http://anask.xyz/ledger/react-check', {
			method: 'POST',
			headers: {
				'Accept': 'application/json',
				'Content-Type': 'application/json',
			},
			body: JSON.stringify({
				led: 'heyy',
				secondParam: 'yourOtherValue',
			})
		}).then((response) => response.json())
			.then((responseJson) => {
				this.setState({
					showText: JSON.stringify(responseJson)
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
	}
	render() {
		const timeOptions = [
    		"9 AM",
    		"3 PM",
			"6 PM"
  		];
		const LedOptions = [
			"LED 1",
			"LED 2",
			"LED 3",
			"LED 4",
			"LED 5",
			"LED 6",
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
					//direction="column" --- commenting this till the issue is fixed on GitHub
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
			</View>
		);
	}
}

AppRegistry.registerComponent('PillReminder', () => PillReminder);
