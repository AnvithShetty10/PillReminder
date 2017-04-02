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
		this.state = { showText: null };

		this.clickHandler = this.clickHandler.bind(this);
	}
	render() {
		const options = [
    		"9 AM",
    		"3 PM",
			"6 PM"
  		];

  		function setSelectedOption(selectedOption){
    		this.setState({selectedOption});
  		}
		let check = this.state.showText ? this.state.showText : "Click on any one button (with time) to proceed";
		return (
			<View style={{ padding: 20, flex: 1 }}>
				<Button
          style={{ padding: 20 }}
					onPress={this.clickHandler}
					title="LED 1 ON"
					color="#841584"
				/>
				<Button
          style={{ padding: 20 }}
					onPress={this.clickHandler}
					title="LED 2 ON"
					color="#841584"
				/>
				<Button
          style={{ padding: 20 }}
					onPress={this.clickHandler}
					title="LED 3 ON"
					color="#841584"
				/>
				<Button
          style={{ padding: 20 }}
					onPress={this.clickHandler}
					title="LED 4 ON"
					color="#841584"
				/>
				<Button
          style={{ padding:20 }}                    
					onPress={this.clickHandler}
					title="LED 5 ON"
					color="#841584"
				/>
				<Button
          style={{ padding:20 }}
					onPress={this.clickHandler}
					title="LED 6 ON"
					color="#841584"
				/>
				<SegmentedControls
 	 				options={ options }
  					onSelection={ setSelectedOption.bind(this) }
  					selectedOption={ this.state.selectedOption }
				/>
				<Text style={{ padding: 20 }}>{check}</Text>
			</View>
		);
	}
}

AppRegistry.registerComponent('PillReminder', () => PillReminder);
